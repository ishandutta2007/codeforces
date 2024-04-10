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
const int N=310;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N*N];
int mark[N][N];
vector<int> comp;
vector<pii> vec[N*N];

inline void sit(int x, int y){
	for (int i=1; i<y; i++) ans+=mark[x][i];
	mark[x][y]=1;
}

int Solve(){
	cin>>n>>m;
	ans=0;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) mark[i][j]=0;
	comp.clear();
	for (int i=1; i<=n*m; i++) cin>>A[i], comp.pb(A[i]), vec[i].clear();
	sort(all(comp));
	for (int i=1; i<=n*m; i++) A[i]=lower_bound(all(comp), A[i])-comp.begin()+1;
	
	int last=-1;
	for (int i=0; i<n*m; i++){
		if (comp[i]!=comp[i+1] || i==n*m-1){
			for (int j=last+1; j<=i; j++){
//				debug2(j+1, last+2)
				vec[last+2].pb({-((j/m)+1), ((j%m)+1)});
			}
			last=i;
		}
	}
	for (int i=1; i<=n*m; i++) sort(all(vec[i]));
	ans=0;
	for (int i=1; i<=n*m; i++){
		pii p=vec[A[i]].back();
		int x=-p.first, y=p.second;
		vec[A[i]].pop_back();
//		debug2(x, y)
		sit(x, y);
	}
	cout<<ans<<"\n";
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
/*
1
2 2
1 1 2 1

*/