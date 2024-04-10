#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, k;
int b[1010], c[1010];
int f[1010];
int dp[1000100];

int main(){
	ios::sync_with_stdio(false);
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for(int i = 1; i <= 1000; i++)
		for(int x = 1; x <= i; x++)
			if(i + i / x <= 1000)
				f[i + i / x] = min(f[i + i / x], f[i] + 1);
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, n)
			cin >> b[i];
		rep(i, n)
			cin >> c[i];
		memset(dp, 0, sizeof(dp));
		rep(i, n)
			for(int j = 12012; j >= 0; j--)
				dp[j + f[b[i]]] = max(dp[j + f[b[i]]], dp[j] + c[i]);
		int ans = 0;
		rep(j, k + 1)
			ans = max(ans, dp[j]);
		cout << ans << endl;
	}
	return 0;
}