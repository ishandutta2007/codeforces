#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 200010;

ll n, k, ans, a, b;
ll A[MAXN];
ll ps[MAXN];
int dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>ps[i];
		ps[i]+=ps[i-1];
	}
	n-=k-1;
	for (int i=1; i<=n; i++) A[i]=ps[i+k-1]-ps[i-1];
	//for (int i=1; i<=n; i++) cerr<<A[i]<<' ';cerr<<endl;
	for (int i=n; i; i--) {
		dp[i]=i;
		if (A[dp[i+1]]>A[i]) dp[i]=dp[i+1];
	}
	//for (int i=1; i<=n; i++) cerr<<dp[i]<<' ';cerr<<endl;
	for (int i=1; i<=n-k; i++){
		if (A[i]+A[dp[i+k]]>ans){
			a=i;
			b=dp[i+k];
			ans=A[i]+A[dp[i+k]];
		}
	}
	cout<<a<<' '<<b<<endl;
	return 0;
}