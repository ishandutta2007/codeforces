#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
int a[100100];
int pre[100100];
int dp[100100];
map<int, int> val;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		rep(i, n)
			pre[i + 1] = pre[i] ^ a[i];
		val.clear();
		val[0] = 0;
		dp[0] = 0;
		for(int i = 1; i <= n; i++){
			dp[i] = dp[i - 1];
			if(val.count(pre[i]))
				dp[i] = max(dp[i], val[pre[i]] + 1);
			val[pre[i]] = dp[i];
		}
		cout << n - dp[n] << "\n";
	}
	return 0;
}