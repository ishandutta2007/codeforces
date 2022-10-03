#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const int inf=1000000010;
const int MAXN = 1010;

ll n, m, k, u, v, x, y, t, a, b;
pll A[MAXN];
ll B[MAXN];
int dp[MAXN][6721], par[MAXN][6721];
ll sum[MAXN][6721];
vector<ll> D, prime;
vector<int> out;
unordered_map<ll, int> id;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i].first, A[i].second=i;
	sort(A+1, A+n+1);
	if (k==1){
		cout<<"1\n"<<A[1].second;
		return 0;
	}
	for (int i=1; i<=n; i++) B[i]=__gcd(A[i].first, k);
	ll tmp=k;
	for (ll i=1; i*i<=k; i++) if (k%i==0){
		D.pb(i);
		if (i*i!=k) D.pb(k/i);
		if (tmp%i==0 && i>1){
			prime.pb(i);
			while (tmp%i==0) tmp/=i;
		}
	}
	if (tmp>1) prime.pb(tmp);
	
	sort(all(D));
	m=D.size();
	
	for (int i=1; i<m; i++) dp[0][i]=inf;
	for (int i=1; i<=n; i++) for (int j=1; j<m; j++){
		dp[i][j]=dp[i-1][j];
		par[i][j]=j;
		sum[i][j]=sum[i-1][j];
		ll y=D[j]/__gcd(D[j], B[i]), ind=lower_bound(all(D), y)-D.begin();
		if (dp[i-1][ind]+1<dp[i][j] || dp[i-1][ind]+1==dp[i][j] && sum[i][j]>sum[i-1][ind]+A[i].first){
			dp[i][j]=dp[i-1][ind]+1;
			par[i][j]=ind;
			sum[i][j]=sum[i-1][ind]+A[i].first;
		}
	}
	
	if (dp[n][m-1]>=inf) return puts("-1");
	
	tmp=m-1;
	for (int i=n; i; i--){
		if (tmp!=par[i][tmp]){
			tmp=par[i][tmp];
			out.pb(i);
		}
	}
	cout<<out.size()<<'\n';
	for (int i:out) cout<<A[i].second<<' ';
	cout<<'\n';
	
	return 0;
}