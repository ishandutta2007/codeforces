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
const int MAXN=300010, N=22;

int n, m, k, u, v, x, y, a, b, ans;
char S[MAXN];
ll dp[1<<N], A[N][N], t[N], T;
int last[N], P[N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>T;
	for (int i=1; i<=n; i++) cin>>S[i];
	for (int i=0; i<k; i++) cin>>t[i];
	for (int i=0; i<k; i++) for (int j=0; j<k; j++) cin>>A[i][j];
	for (int i=1; i<=n; i++){
		iota(P, P+k, 0);
		sort(P, P+k, [](int i, int j){
			return last[i]>last[j];	
		});
		int mask=(1<<k)-1;
		for (int j=0; j<k && last[P[j]]; j++){
			int x=P[j], y=S[i]-'A';
//			cerr<<"adj "<<x<<" "<<y<<": "<<mask<<"\n";
			if (x==y){
				dp[mask^(1<<x)]-=A[x][x];
				dp[mask]+=A[x][x];
				break ;
			}
			dp[mask^(1<<x)^(1<<y)]+=A[x][y];
			dp[mask^(1<<x)]-=A[x][y];
			dp[mask^(1<<y)]-=A[x][y];
			dp[mask]+=A[x][y];
			mask^=(1<<x);
		}
		last[S[i]-'A']=i;
	}
	int mask=0;
	for (int i=0; i<k; i++) if (last[i]) mask|=(1<<i), dp[(1<<k)-1-(1<<i)]+=t[i];
	for (int i=0; i<k; i++) for (int j=0; j<(1<<k); j++) if (j&(1<<i)) dp[j^(1<<i)]+=dp[j];
	for (int i=1; i<(1<<k); i++) if ((mask&i)==i && (mask|i)==mask) ans+=(dp[i]<=T);
	cout<<ans<<"\n";

	return 0;
}