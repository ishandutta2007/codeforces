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
const int mod=998244353;
const int N=505;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[2*N][N], ted[N][N], dead[2*N], col[2*N];
bool G[2*N][2*N];
vector<int> out, vec[N][N];

int get(int pos, int val){
	assert(ted[pos][val]);
//	ted[pos][val]--;
	int res=vec[pos][val].back();
	vec[pos][val].pop_back();
	while (dead[res]){
		res=vec[pos][val].back();
		vec[pos][val].pop_back();
	}
	return res;
}
void Kill(int id){
	dead[id]=1;
	for (int i=1; i<=n; i++) ted[i][A[id][i]]--;
}
void dfs(int node, int c){
	col[node]=c;
	for (int v=1; v<=2*n; v++) if (G[node][v] && !col[v]) dfs(v, 3-c);
}

void Solve(){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			ted[i][j]=0;
			vec[i][j].clear();
		}
	}
	for (int i=1; i<=2*n; i++){
		dead[i]=0;
		col[i]=0;
		for (int j=1; j<=2*n; j++){
			G[i][j]=0;
		}
	}
	out.clear();
	ans=1;
	cin>>n;
	for (int i=1; i<=2*n; i++) for (int j=1; j<=n; j++){
		cin>>A[i][j];
		vec[j][A[i][j]].pb(i);
		ted[j][A[i][j]]++;
	}
	while (1){
		int pos=-1, val=-1;
		for (int i=1; i<=n; i++) for (int j=1; j<=n && pos==-1; j++) if (ted[i][j]==1){
			pos=i;
			val=j;
		}
		if (pos==-1) break ;
		int id=get(pos, val);
		Kill(id);
		out.pb(id);
		for (int i=1; i<=2*n; i++) if (!dead[i]){
			int bad=0;
			for (int j=1; j<=n && !bad; j++) bad|=(A[id][j]==A[i][j]);
			if (bad) Kill(i);
		}
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (ted[i][j]){
		assert(ted[i][j]==2);
		int x=get(i, j);
		int y=get(i, j);
		G[x][y]=G[y][x]=1;
	}
	for (int i=1; i<=2*n; i++) if (!col[i] && !dead[i]){
		dfs(i, 1);
		ans=ans*2ll%mod;
	}
	for (int i=1; i<=2*n; i++) if (col[i]==1) out.pb(i);
	
	cout<<ans<<"\n";
	for (int i:out) cout<<i<<" ";cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}