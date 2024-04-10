#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int ans[MAXN];
int deg[MAXN];
vector<int> G[MAXN];
queue<int> Q;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>u>>v;
		G[u].pb(v);
		deg[v]++;
		ans[i]=(u<v)+1;
	}
	for (int i=1; i<=n; i++) if (!deg[i]) Q.push(i);
	int cnt=0;
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		//debug(v)
		cnt++;
		for (int x:G[v]) if (!(--deg[x])) Q.push(x);
	}
	if (cnt==n){
		cout<<"1\n";
		for (int i=1; i<=m; i++) cout<<"1 ";
		return 0;
	}
	
	cout<<(*max_element(ans+1, ans+m+1))<<'\n';
	for (int i=1; i<=m; i++) cout<<ans[i]<<" \n"[i==m];
	
	return 0;
}