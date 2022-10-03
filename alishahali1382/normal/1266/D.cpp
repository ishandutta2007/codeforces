#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, ll> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll deg[MAXN];  // dout - din
vector<int> vec;
vector<piii> out;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v>>x;
		deg[u]+=x;
		deg[v]-=x;
	}
	for (int i=1; i<=n; i++) if (deg[i]<0) vec.pb(i);
	for (int i=1; i<=n; i++) while (deg[i]>0){
		int v=vec.back();
		ll tmp=min(deg[i], -deg[v]);
		deg[v]+=tmp;
		deg[i]-=tmp;
		if (!deg[v]) vec.pop_back();
		if (tmp) out.pb({{i, v}, tmp}); 
	}
	cout<<out.size()<<'\n';
	for (auto p:out) cout<<p.first.first<<' '<<p.first.second<<' '<<p.second<<'\n';
	
	return 0;
}