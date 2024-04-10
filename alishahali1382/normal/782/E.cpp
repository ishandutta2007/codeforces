#include <bits/stdc++.h>
//#pragma GCC optimize ("O2")
//#pragma GCC optimize ("unroll-loops")
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
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
bool mark[MAXN];
vector<int> G[MAXN];
vector<int> path;

void dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]){
		path.pb(v);
		dfs(v);
		path.pb(node);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	if (n==1) kill("1 1")
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	path.pb(1);
	dfs(1);
	int len=(2*n+k-1)/k;
	//kill(len)
	while (k--){
		int tmp=min(len, (int)path.size());
		if (tmp==0){
			cout<<"1 1\n";
			continue ;
		}
		cout<<tmp<<' ';
		while (tmp--){
			cout<<path.back()<<' ';
			path.pop_back();
		}
		cout<<endl;
	}
	
	
	return 0;
}