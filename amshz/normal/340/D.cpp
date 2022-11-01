# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
int a[xn], dp[xn], lst[xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=1; i<n; i++) lst[i] = 1e9+10;
	for (int i=0; i<n; i++){
		int k = lower_bound(lst, lst+n, a[i]) - lst - 1;
		dp[i] = k+1;
		lst[k+1] = min(lst[k+1], a[i]);
	}
	int mx = 0;
	for (int i=0; i<n; i++) mx = max(mx, dp[i]);
	cout << mx << endl;
}