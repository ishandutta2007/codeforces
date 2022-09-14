//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <limits.h>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10, mod = 998244353;

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int my_pow(int x, int y) {
	int ans = 1;
	
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int f[maxn], rf[maxn];

int cnt[maxn];

int t[4 * maxn];

void build(int it, int l, int r) {
	if (l == r) {
		if (cnt[l] == 0) {
			t[it] = 0;
		} else {
			t[it] = mul(f[cnt[l]], rf[cnt[l] - 1]);
		}
	} else {
		int m = (l + r) >> 1;
		
		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
		t[it] = add(t[2 * it], t[2 * it + 1]);
	}
}

void change(int it, int l, int r, int pos) {
	if (l == r) {
		cnt[l]--;
		assert(cnt[l] >= 0);
		if (cnt[l] == 0) {
			t[it] = 0;
		} else {
			t[it] = mul(f[cnt[l]], rf[cnt[l] - 1]);
		}
	} else {
		int m = (l + r) >> 1;
		
		if (pos <= m) {
			change(2 * it, l, m, pos);
		} else {
			change(2 * it + 1, m + 1, r, pos);
		}
		
		t[it] = add(t[2 * it], t[2 * it + 1]);
	}
}

int go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return t[it];
	} else {
		int m = (l + r) >> 1;
		
		if (rm <= m) {
			return go(2 * it, l, m, lm, rm);
		} else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm);
		} else {
			return add(go(2 * it, l, m, lm, m), go(2 * it + 1, m + 1, r, m + 1, rm));
		}
	}
}

int main() {
	f[0] = 1;
	
	for (int i = 1; i < maxn; i++) {
		f[i] = mul(f[i - 1], i);
	}
	
	rf[maxn - 1] = my_pow(f[maxn - 1], mod - 2);
	
	for (int i = maxn - 2; i >= 0; i--) {
		rf[i] = mul(rf[i + 1], i + 1);
	}
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	
	int tot = f[n];
	
	for (int i = 0; i < maxn; i++) {
		tot = mul(tot, rf[cnt[i]]);
	}
	
	build(1, 0, maxn - 1);
	
	int ans = 0;
	
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		
		if (i < n) {
			tot = mul(tot, rf[n - i]);
			tot = mul(tot, f[n - i - 1]);
		} else {
			tot = 0;
		}
		
		if (i == n) {
			ans = add(ans, 1);
		}
		
		if (x != 0) {
			ans = add(ans, mul(tot, go(1, 0, maxn - 1, 0, x - 1)));
		}
		
		if (cnt[x] == 0) {
			break;
		}
		
		tot = mul(tot, f[cnt[x]]);
		tot = mul(tot, rf[cnt[x] - 1]);
		change(1, 0, maxn - 1, x);
	}
	
	cout << ans << '\n';
}