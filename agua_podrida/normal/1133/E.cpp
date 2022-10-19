#include<bits/stdc++.h>

using namespace std;

#define F1(i,n) for(int i = 1; i <= n; i++)
#define F0(i,n) for(long long i = 0; i < n; i++)
#define F first
#define S second
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;

int main(){
	int n,k;
	cin>>n>>k;
	vi a(n);
	F0(i,n) cin>>a[i];
	sort(a.begin(),a.end());
	vi maximal(n);
	int l = 0;
	int r = 0;
	while(l < n){
		while(r < n and a[r] - a[l] <= 5) r++;
		maximal[l] = r-l;
		l++;
	}
	vvi dp(n+5,vi(k+1));
	F1(i,k-1) dp[n-1][i] = 1;

	int res = 1;

	for(int i = n-2; i >= 0; i--){
		F1(e,k){
			dp[i][e] = dp[i+1][e];
			if(e > 0) dp[i][e] = max(dp[i][e],dp[i+maximal[i]][e-1]+maximal[i]);
			res = max(res,dp[i][e]);
		}
	}

	cout<<res<<'\n';
}