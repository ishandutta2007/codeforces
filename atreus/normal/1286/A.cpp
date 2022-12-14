#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 100 + 7;

int dp1[maxn][maxn], dp0[maxn][maxn];
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int od = (n + 1) / 2, ev = n / 2;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset(dp0, 63, sizeof dp0);
	memset(dp1, 63, sizeof dp1);
	dp0[0][0] = dp1[0][0] = 0;
	for (int i = 1; i <= n; i++){
		bool odd = 1, even = 1;
		if (a[i] != 0){
			if (a[i] & 1)
				even = 0;
			else
				odd = 0;
		}
		if (odd)
			for (int j = 1; j <= min(i, od); j++)
				dp1[i][j] = min(dp0[i - 1][j - 1] + 1, dp1[i - 1][j - 1]);
		if (even){
			dp0[i][0] = dp0[i - 1][0];
			for (int j = 1; j <= min(i, od); j++)
				dp0[i][j] = min(dp1[i - 1][j] + 1, dp0[i - 1][j]);
		}
	}
	cout << min(dp0[n][od], dp1[n][od]) << endl;
}