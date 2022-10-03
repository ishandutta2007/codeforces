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

int n, m, k, u, v, x, y, t, a, b, pos, LIS, last=inf;
int A[MAXN], B[MAXN], ans[MAXN];
int dp[MAXN], mn[MAXN], ind[MAXN], par[MAXN];
bool mark[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], ans[i]=A[i];
	cin>>m;
	for (int i=1; i<=m; i++) cin>>B[i];
	sort(B+1, B+m+1);
	fill(mn+1, mn+n+1, inf);
	for (int i=1; i<=n; i++){
		if (A[i]!=-1){
			int lb=lower_bound(mn, mn+n+1, A[i])-mn;
			dp[i]=lb;
			ind[lb]=i;
			mn[lb]=A[i];
			if (lb) par[i]=ind[lb-1];
			if (dp[i]>LIS){
				LIS=dp[i];
				pos=i;
			}
			continue ;
		}
		// k<=1000 times
		int lb=n;
		for (int j=m; j; j--){
			while (lb && mn[lb-1]>=B[j]) lb--;
			if (lb>LIS){
				LIS=lb;
				pos=i;
			}
			ind[lb]=i;
			mn[lb]=B[j];
		}
	}
//	debug(LIS)
	while (LIS--){
		if (A[pos]!=-1){
			last=A[pos];
			pos=par[pos];
			continue ;
		}
		for (int i=m; i; i--) if (B[i]<last){
			last=ans[pos]=B[i];
			mark[i]=1;
			break ;
		}
		if (!LIS) break ;
		
		int ok=0, tmp=0;
		for (int i=1; i<pos; i++){
			if (A[i]==-1) tmp=i;
			else if (dp[i]==LIS && A[i]<last){
				pos=i;
				ok=1;
				break ;
			}
		}
		if (ok) continue ;
		pos=tmp;
	}
	for (int i=1; i<=n; i++) if (ans[i]==-1){
		for (int j=1; j<=m; j++) if (!mark[j]){
			ans[i]=B[j];
			mark[j]=1;
			break ;
		}
	}
	for (int i=1; i<=n; i++) cout<<ans[i]<<" \n"[i==n];
	
	return 0;
}