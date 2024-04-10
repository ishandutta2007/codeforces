# include <bits/stdc++.h>
 
using namespace std;
 
const int xn = 2e5+10;
const long long md = 1e9+7;
long long int dp[xn][2];
 
long long int f1(long long n){
	return ((n*(n+1))/2);
}
 
int main(){
	long long int rd,g,l,r,mid;
	cin >> rd >> g;
	l = 1, r = 900;
	while (l+1 < r){
		mid = (l+r)/2;
		if (f1(mid) <= rd+g) l = mid;
		else r = mid;
	}
	int h = l;
	if (f1(r) <= rd+g) h = r;
	dp[0][0] = 1;
	for (int i=0; i<=h; i++){
		for (int j=0; j<=rd; j++){
			if (i == 0 and j == 0) continue;
			dp[j][i%2] = 0;
			if (j >= i) dp[j][i%2] += dp[j-i][(i+1)%2];
			if (g >= i*(i+1)/2-j) dp[j][i%2] += dp[j][(i+1)%2];
			dp[j][i%2] %= md;
		}
	}
	long long ans = 0;
	for (int i=0; i<=rd; i++) ans += dp[i][h%2], ans %= md;
	cout << ans << endl;
}