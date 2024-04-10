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
const int N=260;

int n, m, k, u, v, x, y, t, a, b;
int A[3*N][3*N], mark[3*N][3*N];
ll dist[3*N][3*N], ps1[2*N][3*N], ps2[3*N][2*N];
//priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;

//inline void upd(int x, int y, ll d){
////	cerr<<"upd "<<x<<" "<<y<<"  "<<d<<"\n";
//	if (dist[x][y]>d) pq.push({dist[x][y]=d, {x, y}});
//}

int Main(){
//	memset(mark, 0, sizeof(mark));
//	memset(dist, 63, sizeof(dist));
//	memset(ps1, 0, sizeof(ps1));
//	memset(ps2, 0, sizeof(ps2));
	cin>>n;
	for (int i=1; i<=2*n; i++) for (int j=1; j<=2*n; j++) cin>>A[i+n][j+n];
	for (int i=1; i<=3*n; i++) for (int j=1; j<=3*n; j++){
		int x=i, y=j;
		if (x<=n) x+=2*n;
		if (y<=n) y+=2*n;
		A[i][j]=A[x][y]; 
	}
	/*
	for (int i=1; i<=2*n+1; i++) for (int j=1; j<=3*n; j++){
		for (int ii=i; ii<i+n; ii++) ps1[i][j]+=A[ii][j];
	}
	for (int i=1; i<=3*n; i++) for (int j=1; j<=2*n+1; j++){
		for (int jj=j; jj<j+n; jj++) ps2[i][j]+=A[i][jj];
	}
//	debug(ps2[2][3])
	
	pq.push({dist[n+1][n+1]=0, {n+1, n+1}});
	while (SZ(pq)){
		pii p=pq.top().second;
		pq.pop();
		int x=p.first, y=p.second;
		if (mark[x][y]) continue ;
		mark[x][y]=1;
//		debug2(x, y)
//		debug(dist[x][y])
		
		if (x!=1) upd(x-1, y, dist[x][y]+ps2[x-1][y]);
		if (x<=2*n) upd(x+1, y, dist[x][y]+ps2[x+n][y]);
		if (y!=1) upd(x, y-1, dist[x][y]+ps1[x][y-1]);
		if (y<=2*n) upd(x, y+1, dist[x][y]+ps1[x][y+n]);
	}
	ll ans=INF;
	for (int x:{1, 2*n+1}) for (int y:{1, 2*n+1}) ans=min(ans, dist[x][y]);
	cout<<ans<<"\n";
	*/
	
	ll ans=INF;
	ans=min(ans, 1ll*min(A[2*n+1][2*n], A[2*n][2*n+1]));
	ans=min(ans, 1ll*min(A[n+1][2*n+1], A[2*n+1][n+1]));
//	debug(ans)
	ans=min(ans, 1ll*min(A[n][2*n], A[2*n][n]));
	ans=min(ans, 1ll*min(A[n][n+1], A[n+1][n]));
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) ans+=A[2*n+i][2*n+j];
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
2
0 0 4 2
0 0 2 4
4 2 4 2
2 4 2 4

*/