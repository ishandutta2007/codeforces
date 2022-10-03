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
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=40, LOG=21;

int n, m, k, u, v, x, y, t, L, R, ans;
int V[N];
vector<pii> G[N];
vector<pair<pii, int>> E;

inline void add_edge(int u, int v, int w){
	w=min(w, 1000000);
	E.pb({{u, v}, w});
	G[u].pb({v, w});
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>L>>R;
	n=32;
	int nn=n;
	V[0]=--nn;
	add_edge(V[0], n, 1);
	for (int i=1; i<LOG; i++){
		V[i]=--nn;
		for (pii p:G[V[i-1]]) add_edge(V[i], p.first, p.second);
		add_edge(V[i], V[i-1], 1<<(i-1));
	}
	R++;
	if (L==1) add_edge(1, n, L++);
	for (int i=LOG-1; ~i; i--) if (L+(1<<i)<=R){
		add_edge(1, V[i], L-1);
		L+=(1<<i);
	}
	cout<<"YES\n";
	cout<<n<<" "<<E.size()<<"\n";
	for (auto p:E) cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<"\n";
	
	return 0;
}