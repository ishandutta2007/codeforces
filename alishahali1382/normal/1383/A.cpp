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
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
bool G[20][20], mark[20];
string A, B;

void dfs(int v){
	mark[v]=1;
	for (int u=0; u<20; u++) if ((G[v][u] || G[u][v]) && !mark[u]) dfs(u);
}

int Solve(){
	cin>>n>>A>>B;
	for (int i=0; i<n; i++) if (A[i]>B[i]) kill(-1)
	for (int i=0; i<20; i++){
		mark[i]=0;
		for (int j=0; j<20; j++) G[i][j]=0;
	}
	for (int i=0; i<n; i++) G[A[i]-'a'][B[i]-'a']=1;
	ans=20;
	for (int i=0; i<20; i++) if (!mark[i]) dfs(i), ans--;
	
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);	
	int Test;
	cin>>Test;
	while (Test--) Solve();
	
	return 0;
}