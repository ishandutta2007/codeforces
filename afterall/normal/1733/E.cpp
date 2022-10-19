#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=125;
ll dp[N][N];
void solve(ll x){
	memset(dp,0,sizeof dp);
	if (x<0) return ;
	dp[1][1]=x+1;
	for (int i=1;i<=N;i++){
		for (int j=1;j<N;j++){
			if (i+j>2) dp[i][j]=(dp[i-1][j]/2+(dp[i][j-1]+1)/2);
		}
	}
}
int32_t main(){
	sync;
	ll q;
	cin >> q;
	while(q--){
		ll t,x,y;
		cin >> t >> x >> y;
		if (t<x+y){
			cout << "NO" << endl;
			continue;
		}
		solve(t-x-y);
		x++;
		y++;
		ll w=dp[x][y];
		solve(t-x-y+1);
		if (w>dp[x][y]){
			cout << "YES" << endl;
		}
		else cout << "NO"  << endl;

	}
}