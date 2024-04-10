#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int n, c;
int a[200200];
int b[200200];
int dp[200200];
int main () {
	cin >> n >> c;
	for(int i = 0; i < n-1; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n-1; i++)
		cin >> b[i];
	dp[0] = 0;
	int cur1 = 2e9;
	int cur2 = 2e9;
	for(int i=0; i < n-1;i++) {
		cur1 = min(dp[i], cur1) + a[i];
		cur2 = min(dp[i]+c, cur2) + b[i];
		dp[i+1] = min(cur1, cur2);
	}
	for(int i = 0; i < n; i++) cout << dp[i] << " ";
 	return 0;
}