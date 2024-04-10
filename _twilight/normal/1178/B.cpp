#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e6 + 5;

#define ll long long

int n;
char s[N];
ll f[N][4];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		memcpy(f[i], f[i - 1], sizeof(f[i]));
		if (s[i] == 'v' && s[i - 1] == 'v') {
			f[i][1] += f[i - 2][0];
			f[i][3] += f[i - 2][2];
		}
		if (s[i] == 'o') {
			f[i][2] += f[i - 1][1]; 
		}
	}
	printf("%lld\n", f[n][3]);
	return 0;
}