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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=300010, LOG=32;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], typ[MAXN];
ll fen[MAXN];
set<int> st[LOG];

inline void upd(int pos, ll x){ for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=x;}
inline ll get(int pos){
	ll res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}
inline int gett(int x){
	if (!x) return 31;
	return 31-__builtin_clz(x);
} 

int Solve(){
	cin>>x>>y;
	upd(x, y-A[x]);
	st[typ[x]].erase(x);
	typ[x]=gett(A[x]=y);
	st[typ[x]].insert(x);
	for (int i=0; i<LOG; i++){
		auto it=st[i].begin();
		int ted=2;
		while (ted-- && it!=st[i].end()){
			int x=*it;
			if (get(x-1)==A[x]) kill(x)
			it++;
		}
	}
	kill(-1)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		st[typ[i]=gett(A[i])].insert(i);
		upd(i, A[i]);
	}
	while (m--) Solve();
	
	return 0;
}