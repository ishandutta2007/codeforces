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
const int MAXN=110, N=14;

int n, m, k, u, v, x, y, t, a, b, ans;
pii A[MAXN];
pair<int, pii> B[MAXN];
int dp1[MAXN][1<<N];
int dp2[MAXN][1<<N];
int bst1[N][1<<N];
int bst2[MAXN][1<<N], T;

inline int dist(pii i, pii j){ return abs(i.first-j.first)+abs(i.second-j.second);}
inline bool upd(int &x, int y){
	if (x<=y) return 0;
	x=y;
	return 1;
}
void relax(int t){
	for (int mask=0; mask<(1<<n); mask++) if (T<=dp2[t][mask] && dp2[t][mask]<inf){
		for (int i=0; i<n; i++) if (!(mask&(1<<i)))
			upd(dp2[t][mask|(1<<i)], dp2[t][mask]+bst1[i][mask]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++) cin>>A[i].first>>A[i].second;
	for (int i=0; i<m; i++) cin>>B[i].second.first>>B[i].second.second>>B[i].first;
	sort(B, B+m);
	
	for (int i=0; i<n; i++) for (int mask=0; mask<(1<<n); mask++){
		bst1[i][mask]=inf;
		for (int j=0; j<n; j++) if (mask&(1<<j)) upd(bst1[i][mask], dist(A[i], A[j]));
	}
	for (int i=0; i<m; i++) for (int mask=0; mask<(1<<n); mask++){
		bst2[i][mask]=inf;
		for (int j=0; j<n; j++) if (mask&(1<<j)) upd(bst2[i][mask], dist(B[i].second, A[j]));
	}
	
	memset(dp1, -31, sizeof(dp1));
	memset(dp2, 63, sizeof(dp2));
	dp2[0][0]=0;
	for (int i=0; i<n; i++) upd(dp2[0][1<<i], 0);
	relax(0);
	for (int i=0; i<m; i++){
		int t=B[i].first;
		pii pos=B[i].second;
		T=t;
		dp1[i][0]=1;
		for (int j=0; j<i; j++) for (int mask=0; mask<(1<<n); mask++){
			if (B[j].first+dist(B[j].second, pos)<=t) dp1[i][mask]=max(dp1[i][mask], dp1[j][mask]+1);
		}
		
		for (int j=0; j<=i; j++) for (int mask=0; mask<(1<<n); mask++)
			if (dp2[j][mask]+bst2[i][mask]<=t) dp1[i][mask]=max(dp1[i][mask], j+1);
		
		for (int mask=0; mask<(1<<n); mask++) if (dp1[i][mask]>=0){
			upd(dp2[dp1[i][mask]][mask], t);
			for (int k=0; k<n; k++){
				upd(dp2[dp1[i][mask]][mask|(1<<k)], t+dist(A[k], pos));	
			}
		}
		for (int mask=0; mask<(1<<n); mask++) ans=max(ans, dp1[i][mask]);
		for (int j=0; j<=ans; j++) relax(j);
	}
	cout<<ans<<"\n";
	
	return 0;
}