#include <bits/stdc++.h>
#define gcd __gcd
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int divs[MAXN];
int perm[10][5];

void init() {
	int tmp[3] = {0, 1, 2};
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++)
			perm[i][j] = tmp[j];
		next_permutation(tmp, tmp + 3);
	}
	
	for (int i = 1; i < MAXN; i++)
		for (int j = i; j < MAXN; j += i)
			divs[j]++;
}

ll solve(int a, int b, int c) {
	int arr[3] = {a, b, c};
	ll x = divs[gcd(a, gcd(b, c))];
	ll y = 0, tot = 0;
	for (int i = 1; i < 64; i++) {
		int tmp[3] = {0};
		for (int j = 0; j < 6; j++)
			if (i >> j & 1)
				for (int k = 0; k < 3; k++)
					tmp[k] = gcd(tmp[k], arr[perm[j][k]]);
		ll coef = __builtin_popcount(i) % 2 ? 1 : -1;
		tot += coef * divs[tmp[0]] * divs[tmp[1]] * divs[tmp[2]];
		tmp[0] = gcd(tmp[0], tmp[1]);
		y += coef * (divs[tmp[0]] * divs[tmp[2]] - divs[gcd(tmp[0], tmp[2])]);
	}
	
	ll z = (tot - x - 3 * y) / 6;
	return x + y + z;
}

int main() {
	init();
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		printf("%lld\n", solve(a, b, c));
	}
	return 0;
}