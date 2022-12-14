#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 500 + 5;
const int mod = 1e9 + 7;

int a[maxn];
int dp[maxn][maxn], pd[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int len = 1; len <= n; len++){
		for (int i = 1; i + len <= n + 1; i++){
			int j = i + len;
			if (len == 1){
				dp[i][j] = 1;
				pd[i][j] = 1;
				continue;
			}
			ll tmp = 1;
			pd[i][j] = dp[i + 1][j];
			/*
			for (int k = i + 2; k <= j; k++){
				if (a[k] >= a[i + 1]){
					pd[i][j] = (pd[i][j] + 1ll * pd[i + 1][k] * dp[k][j]) % mod;
				}
			}
			*/
			for (int k = i + 1; k <= j; k++){
				if (a[k] >= a[i]){
					dp[i][j] = (dp[i][j] + 1ll * pd[i][k] * dp[k][j]) % mod;
				}
			}
			dp[i][j] = (dp[i][j] + pd[i][j]) % mod;
		}
	}
	cout << pd[1][n + 1] << endl;
}