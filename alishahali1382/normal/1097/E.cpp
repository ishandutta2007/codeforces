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

int n, m, k, u, v, x, y, t, a, b, ans, lis;
int A[MAXN], mark[MAXN];
int dp[MAXN], mn[MAXN], par[MAXN], ind[MAXN];
vector<vector<int>> out;

inline void LIS(){
	fill(mn+1, mn+n+1, inf);
	lis=0;
	for (int i=1; i<=n; i++) if (!mark[i]){
		int lb=lower_bound(mn, mn+n+1, A[i])-mn;
		lis=max(lis, lb);
		mn[lb]=A[i];
		ind[lb]=i;
		par[i]=ind[lb-1];
		dp[i]=lb;
	}
}

void Solve(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], mark[i]=0;
	ans=0;
	while ((ans+2)*(ans+1)/2<n) ans++;
	out.clear();
	int flag=1;
	while (flag--){
		LIS();
		if (ans-->=lis){
			while (lis){
				out.pb({});
				for (int i=1; i<=n; i++) if (!mark[i] && dp[i]==lis){
					out.back().pb(A[i]);
					mark[i]=1;
				}
				lis--;
			}
			break ;
		}
		out.pb({});
		int pos=ind[lis];
		while (pos){
//			assert(!mark[pos]);
			mark[pos]=1;
			out.back().pb(A[pos]);
			pos=par[pos];
		}
//		assert(out.back().size()==lis);
		reverse(all(out.back()));
		
		for (int i=1; i<=n && !flag; i++) if (!mark[i]) flag=1;
	}
	cout<<out.size()<<"\n";
	for (auto vec:out){
		cout<<vec.size()<<" ";
		for (int x:vec) cout<<x<<" ";
		cout<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	n=100000;
	int ted=370;
	while (n--){
		
	}
	
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}