#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, T=50, MX=1000;

struct Fenwick{
	int fen[MAXN];
	void add(int pos, int x){
		for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=x;
	}
	int get(int pos){
		int res=0;
		for (; pos; pos-=pos&-pos) res+=fen[pos];
		return res;
	}
} fen[T];

int n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN];
int Q[MAXN][4];
int H[MAXN*2][T];
vector<int> comp;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_hash(int i, int x){
	return H[x][i];
}

int query(int l, int r, int k){
	for (int i=0; i<T; i++){
		int sum=fen[i].get(r)-fen[i].get(l-1);
		if (sum%k) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		comp.pb(A[i]);
	}
	for (int i=1; i<=m; i++){
		cin>>Q[i][0];
		if (Q[i][0]==1){
			cin>>Q[i][1]>>Q[i][2];
			comp.pb(Q[i][2]);
		}
		else{
			cin>>Q[i][1]>>Q[i][2]>>Q[i][3];
		}
	}
	
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	for (int i=0; i<SZ(comp); i++){
		for (int j=0; j<T; j++){
			H[i][j]=rng()%MX+1;
		}
	}
	for (int i=1; i<=n; i++) A[i]=lower_bound(all(comp), A[i])-comp.begin();
	for (int i=1; i<=m; i++) if (Q[i][0]==1) Q[i][2]=lower_bound(all(comp), Q[i][2])-comp.begin();
	
	for (int i=1; i<=n; i++){
		for (int j=0; j<T; j++){
			fen[j].add(i, get_hash(j, A[i]));
		}
	}
	for (int j=1; j<=m; j++){
		if (Q[j][0]==1){
			// A[x]=y;
			x=Q[j][1];
			y=Q[j][2];
			for (int i=0; i<T; i++){
				fen[i].add(x, get_hash(i, y)-get_hash(i, A[x]));
			}
			A[x]=y;
			continue ;
		}
		if (query(Q[j][1], Q[j][2], Q[j][3])) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}