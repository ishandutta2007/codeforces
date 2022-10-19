#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

void update(int &a, int b){
	if(b > a)
		a = b;
}

int t;
int n;
string s[2];
int dp[100100][2][2];

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> s[0] >> s[1];
		rep(i, n + 1) rep(tp0, 2) rep(tp1, 2)
			dp[i][tp0][tp1] = (int)0xc0c0c0c0c0;
		dp[0][0][0] = 0;
		rep(i, n + 1){
			rep(tp0, 2) rep(tp1, 2){
				update(dp[i + 1][tp0 | (s[0][i] == '0') | (s[1][i] == '0')][tp1 | (s[0][i] == '1') | (s[1][i] == '1')], dp[i][tp0][tp1]);
			}
			rep(tp0, 2) rep(tp1, 2){
				update(dp[i + 1][0][0], dp[i + 1][tp0][tp1] + tp0 + (tp0 && tp1));
			}
		}
		cout << dp[n][0][0] << endl;
	}
	return 0;
}