#include<bits/stdc++.h>
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 1e6 + 7 , P = 998244353; int A[_] , N , Q , st[20][200003] , pos[_] , lg2[_];
struct dat{int epos , ql , qr; bool flag;}; vector < dat > qpot; vector < int > pot[200003];
int cmp(int p , int q){return A[p] > A[q] ? p : q;}
int qrys(int L , int R){int pos = lg2[R - L + 1]; return cmp(st[pos][L] , st[pos][R - (1 << pos) + 1]);}
void build(int l , int r){
	if(l >= r) return;
	int posmx = qrys(l , r); build(l , posmx - 1); build(posmx + 1 , r);
#define pii pair < int , int >
	vector < pii > spot;
	for(auto p : pot[A[posmx]]){
		int pos1 = pos[p] , pos2 = pos[A[posmx] / p]; if(pos1 > pos2) swap(pos1 , pos2);
		if(pos1 >= l && pos1 <= r && pos2 >= l && pos2 <= r) spot.push_back(pii(pos1 , pos2));
	}
	sort(spot.begin() , spot.end() , [&](pii p , pii q){return p.first > q.first;});
	int curmxr = r + 1;
	for(auto t : spot){
		t.first = min(t.first , posmx); t.second = max(t.second , posmx); 
		if(t.second < curmxr){
			qpot.push_back((dat){t.first , t.second , curmxr - 1 , 0}); curmxr = t.second;
		}
	}
	if(curmxr <= r) qpot.push_back((dat){l - 1 , curmxr , r , 1});
}
const int __ = _ << 2;
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
int tag[__][2] , sum[__][2];
void mark(int x , int l , int r , int t1 , int t2){
	tag[x][0] += t1; tag[x][1] += t2;
	sum[x][0] += (r - l + 1) * t1; sum[x][1] += (r - l + 1) * t2;
}
void down(int x , int l , int r){
	if(tag[x][1] || tag[x][0]){
		mark(lch , l , mid , tag[x][0] , tag[x][1]);
		mark(rch , mid + 1 , r , tag[x][0] , tag[x][1]);
		tag[x][0] = tag[x][1] = 0;
	}
}
void upd(int x){sum[x][0] = sum[lch][0] + sum[rch][0]; sum[x][1] = sum[lch][1] + sum[rch][1];}
void mdf(int x , int l , int r , int L , int R , int t1 , int t2){
	if(l >= L && r <= R) return mark(x , l , r , t1 , t2);
	down(x , l , r);
	if(mid >= L) mdf(lch , l , mid , L , R , t1 , t2);
	if(mid < R) mdf(rch , mid + 1 , r , L , R , t1 , t2);
	upd(x);
}
pii qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return pii(sum[x][0] , sum[x][1]);
	down(x , l , r); pii ans(0,0);
	if(mid >= L) ans = qry(lch , l , mid , L , R);
	if(mid < R){pii v = qry(rch , mid + 1 , r , L , R); ans.first += v.first; ans.second += v.second;}
	return ans;
}

signed main(){
	N = read(); Q = read(); for(int i = 1 ; i <= N ; ++i){A[i] = read(); st[0][i] = i;}
	for(int i = 1 ; i <= 19 ; ++i)
		for(int j = 1 ; j + (1 << i) - 1 <= N ; ++j)
			st[i][j] = cmp(st[i - 1][j] , st[i - 1][j + (1 << (i - 1))]);
	for(int i = 2 ; i <= N ; ++i) lg2[i] = lg2[i >> 1] + 1;
	for(int i = 1 ; i <= N ; ++i){pos[A[i]] = i;}
	for(int i = 1 ; i <= N ; ++i)
		for(long long j = 1ll * i * (i + 1) ; j <= N ; j += i)
			pot[j].push_back(i);
	build(1 , N);
	for(int i = 1 ; i <= Q ; ++i){
		int l = read() , r = read();
		qpot.push_back((dat){l , r , -i});
	}
	static int ans[_]; sort(qpot.begin() , qpot.end() , [&](dat p , dat q){return p.epos > q.epos || p.epos == q.epos && p.qr > q.qr;});
	for(auto t : qpot)
		if(t.qr < 0){
			pii v = qry(1 , 1 , N , t.epos , t.ql);
			ans[-t.qr] = v.second - v.first * (t.epos - 1);
		}else if(!t.flag) mdf(1 , 1 , N , t.ql , t.qr , 1 , t.epos);
		else mdf(1 , 1 , N , t.ql , t.qr , -1 , -t.epos);
	for(int i = 1 ; i <= Q ; ++i) cout << ans[i] << '\n';
	return 0;
}