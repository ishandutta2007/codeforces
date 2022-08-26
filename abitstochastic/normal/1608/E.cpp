#include<bits/stdc++.h>
using namespace std;

#define pii pair < int , int >
const int _ = 1e5 + 3;
vector < pii > pot[4]; vector < int > lx , ly; int N , ans;
int qlsh(int x , vector < int > &v){return lower_bound(v.begin() , v.end() , x) - v.begin() + 1;}

struct dat{
	vector < pii > D; int sum1[100003] , pos;
	void init(vector < pii > X){
		memset(sum1 , 0 , sizeof(sum1)); D = X; pos = 0; for(auto t : X) ++sum1[t.first];
		for(int i = 1 ; i <= N + 1 ; ++i) sum1[i] += sum1[i - 1];
	}
}X , Y;

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
int mrk[_ << 2][2] , dlt[_ << 2];
void mdf(int x , int l , int r , int L , int R , int c , int v){
	if(l >= L && r <= R){mrk[x][c] += v; dlt[x] += c ? -v : v; return;}
	if(mid >= L) mdf(lch , l , mid , L , R , c , v);
	if(mid < R) mdf(rch , mid + 1 , r , L , R , c , v);
	dlt[x] = dlt[lch] + mrk[x][0] - mrk[x][1];
}

int qry1(int x , int l , int r , int premrk){
	if(l == r) return l;
	premrk += mrk[x][0] - mrk[x][1];
	if(dlt[rch] + premrk <= 0) return qry1(rch , mid + 1 , r , premrk);
	return qry1(lch , l , mid , premrk);
}
int qryv(int x , int l , int r , int t , int c){return l == r ? mrk[x][c] : mrk[x][c] + (mid >= t ? qryv(lch , l , mid , t , c) : qryv(rch , mid + 1 , r , t , c));}
#undef mid
void add(int x , int p , int v){if(!p) mdf(1 , 0 , N + 1 , x + 1 , N + 1 , 0 , v); else mdf(1 , 0 , N + 1 , 0 , x , 1 , v);}

void solve(vector < pii > P , vector < pii > Q , vector < pii > R){
	 X.init(Q); Y.init(R); int pos = 0 , posq = 0 , posr = 0;
	memset(mrk , 0 , sizeof(mrk)); memset(dlt , 0 , sizeof(dlt));
	for(auto t : Q) add(t.second , 0 , 1);
	for(auto t : R) add(t.second , 1 , 1);
	for(int i = 1 ; i <= N ; ++i){
		while(posq < Q.size() && Q[posq].first == i) add(Q[posq++].second , 0 , -1);
		while(posr < R.size() && R[posr].first == i) add(R[posr++].second , 1 , -1);
		
		while(pos < P.size() && P[pos].first == i) ++pos;
		
		int L = i , r = N , cur = 0; while(L < r){int mid = (L + r + 1) >> 1; X.sum1[mid] - X.sum1[i] <= Y.sum1[N + 1] - Y.sum1[mid] ? L = mid : r = mid - 1;}
		cur = max(cur , max(min(X.sum1[L] - X.sum1[i] , Y.sum1[N + 1] - Y.sum1[L]) , min(X.sum1[L + 1] - X.sum1[i] , Y.sum1[N + 1] - Y.sum1[L + 1])));
		
		int T = qry1(1 , 0 , N + 1 , 0);
		cur = max(cur , max(qryv(1 , 0 , N + 1 , T , 0) , T == N + 1 ? -1 : qryv(1 , 0 , N + 1 , T + 1 , 1)));
		ans = max(ans , min(pos , cur)); if(cur <= pos) break;
	}
}

int main(){
	ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i <= N ; ++i){int p , q , x; cin >> p >> q >> x; lx.push_back(p); ly.push_back(q); pot[x].push_back(make_pair(p , q));}
	sort(lx.begin() , lx.end()); sort(ly.begin() , ly.end());
	for(int i = 1 ; i <= 3 ; ++i) for(auto &t : pot[i]){t.first = qlsh(t.first , lx); t.second = qlsh(t.second , ly);}
	for(int j = 0 ; j < 2 ; ++j){
		for(int i = 0 ; i < 4 ; ++i){
			for(int i = 1 ; i <= 3 ; ++i) sort(pot[i].begin() , pot[i].end());
			vector < int > pot = {1,2,3}; do{solve(::pot[pot[0]] , ::pot[pot[1]] , ::pot[pot[2]]);}while(next_permutation(pot.begin() , pot.end()));
			for(int i = 1 ; i <= 3 ; ++i) for(auto &t : ::pot[i]){swap(t.first , t.second); t.first = N + 1 - t.first;}
		}
		for(int i = 1 ; i <= 3 ; ++i) for(auto &t : ::pot[i]) swap(t.first , t.second);
	}
	cout << ans * 3; return 0;
}