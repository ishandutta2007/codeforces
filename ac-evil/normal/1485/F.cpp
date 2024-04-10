#include <bits/stdc++.h>
typedef long long LL;
const int N = 200005, P = 1e9 + 7;
using std::map;
int T, n, f[N], sum; LL s[N];
int main() {
	//freopen("ques.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		map<LL, int> H; s[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &s[i]), s[i] += s[i-1];
		/*H[0] = f[0] = 1; */H[0] = f[1] = sum = 1;
		for (int i = 2; i <= n; i++) {
			//printf("%d %d %d %lld %d\n", sum, H[0LL], i-1, s[i-1], H[s[i-1]]);
			f[i] = (sum + P - H[s[i - 1]]) % P;
			sum = (sum + f[i]) % P;
			H[s[i - 1]] = (H[s[i - 1]] + f[i]) % P;
		}
		//for (int i = 1; i <= n; i++) printf("<%d %d>", s[i], f[i]); puts("");
		printf("%d\n", sum);
	}
	return 0;
}