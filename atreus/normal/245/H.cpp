#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

const int maxn = 5e3 + 500;
int f[maxn][maxn], dp[maxn][maxn];
string s;

int main() {
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++){
        f[i][i] = true;
        dp[i][i] = 1;
        if (i < n - 1 && s[i] == s[i + 1]){
            f[i][i + 1] = true;
            dp[i][i + 1] = 3;
        }
	}
	for (int len = 3; len <= n; len++){
        for (int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            f[i][j] = (f[i + 1][j - 1] && s[i] == s[j]);
        }
	}
	for (int len = 2; len <= n; len++){
        for (int i = 0; i < n; i++){
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + f[i][j];
        }
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", dp[l - 1][r - 1]);
	}
}