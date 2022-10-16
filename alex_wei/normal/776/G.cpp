#include <bits/stdc++.h>
using namespace std;
const int N = 16;
long long q, ans, f[N][2][2];
long long calc(char *s, bool type) {
	long long n = strlen(s), d[N], ans = 0;
	reverse(s, s + n); // ADD THIS LINE
	for(int i = 0; i < n; i++) d[i] = isdigit(s[i]) ? s[i] - '0' : s[i] + 10 - 'a';
	for(int mxd = 0; mxd < N; mxd++) {
		memset(f, 0, sizeof(f)), f[n][0][1] = 1;
		if(mxd >= n << 2) continue;
		for(int p = n; p; p--) {
			for(int x : {0, 1}) {
				for(int y : {0, 1}) {
					if(!f[p][x][y]) continue;
					for(int dig = 0; dig <= mxd; dig++) {
						if((mxd >> 2) == p - 1 && dig >> mxd - (p - 1 << 2) & 1 ^ 1) continue;
						if(y && dig > d[p - 1]) continue;
						f[p - 1][x | (dig == mxd)][y & (dig == d[p - 1])] += f[p][x][y];
					}
				}
			}
		}
		ans += f[0][1][0] + type * f[0][1][1];
	}
	return ans;
}
int main() {
	// freopen("1.in", "r", stdin);
	cin >> q;
	for(int i = 1; i <= q; i++) {
		char s[N];
		scanf("%s", s), ans = -calc(s, 0);
		scanf("%s", s), cout << ans + calc(s, 1) << endl;
	}
	return 0;
}

/*
2022/4/28
start thinking at ??:??

.
 maxdigit , maxdigit .
 maxdigit DP .
f_{i, j, k}  i ,  maxdigit, 
 q * base ^ 2 * log_{base} n 


start coding at 21:13
finish debugging at 21:37
*/