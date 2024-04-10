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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN], shit[MAXN];
int dist[MAXN], par[MAXN];
queue<int> Q;
set<pii> st;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++){
		cin>>B[i];
		shit[i+B[i]]=i;
		st.insert({i, i+B[i]});
	}
	memset(dist, 63, sizeof(dist));
	dist[n]=0;
	Q.push(n);
	while (SZ(Q)){
		int v=Q.front();
		Q.pop();
		if (A[v]==v){
			dist[0]=dist[v]+1;
			par[0]=v;
			break ;
		}
		auto it=st.lower_bound({v-A[v], 0});
		while (it!=st.end() && (it->first)<=v){
			int u=(it->second);
			it=st.erase(it);
			if (dist[u]>dist[v]+1){
				par[u]=v;
				dist[u]=dist[v]+1;
				Q.push(u);
			}
		}
	}
	if (dist[0]>inf) kill(-1)
	vector<int> out;
	int v=0;
	while (v!=n){
		out.pb(v);
		v=par[v];
	}
	cout<<dist[0]<<"\n";
	reverse(all(out));
	for (int i:out) cout<<shit[i]<<" ";cout<<"\n";
	
	return 0;
}