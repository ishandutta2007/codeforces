#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 8000 + 10;
const int mod = 1e9 + 7;
const int base = 103;

int dp[maxn][maxn], ans[maxn];

int digits(int x){
	int ret = 0;
	while (x){
		ret ++;
		x /= 10;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++){
		int k = 0;
		for (int j = i + 1; j < n; j++){
			while (k > 0 and s[i + k] != s[j])
				k = dp[i][i + k];
			k += (s[i + k] == s[j]);
			dp[i][j + 1] = k;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = -1; j < i; j++){
			int per = dp[j + 1][i + 1];
			int len = (i - j);
			if (len % (len - per) == 0)
				per = len - per;
			else
				per = (i - j);
			int num = len / per;
			if (j == -1)
				ans[i] = digits(num) + per;
			else
				ans[i] = min(ans[i], ans[j] + digits(num) + per);
		}
	}
	cout << ans[n - 1] << endl;
}