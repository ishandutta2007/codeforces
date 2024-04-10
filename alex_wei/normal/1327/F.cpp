#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long

#define pii pair <int, int>
#define fi first
#define se second
#define pb push_back
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
//
const int N = 5e5 + 5;
const int mod = 998244353;

struct Limit {
	int l, r, x;
} c[N];
int n, k, m, ans = 1;
int f[N], pos[N], buc[N];

int main() {
	cin >> n >> k >> m;
	for(int i = 1; i <= m; i++)
		scanf("%d %d %d", &c[i].l, &c[i].r, &c[i].x);
	for(int i = 0, s; i < k; i++) {
		mem(f, 0, N), mem(pos, 0, N), mem(buc, 0, N), f[0] = s = 1;
		for(int j = 1; j <= m; j++)
			if(c[j].x >> i & 1) buc[c[j].l]++, buc[c[j].r + 1]--;
			else pos[c[j].r + 1] = max(pos[c[j].r + 1], c[j].l);
		for(int j = 1; j <= n; j++) buc[j] += buc[j - 1];
		for(int j = 1; j <= n; j++) {
			pos[j] = max(pos[j], pos[j - 1]);
			for(int k = pos[j - 1]; k < pos[j]; k++) s = (s + mod - f[k]) % mod;
			if(!buc[j]) f[j] = s; s = (f[j] + s) % mod;
		} for(int k = pos[n]; k < max(pos[n], pos[n + 1]); k++) s = (s + mod - f[k]) % mod;
		ans = 1ll * ans * s % mod;
	} cout << ans << endl;
	return 0;
}