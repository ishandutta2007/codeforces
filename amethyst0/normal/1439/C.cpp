#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <random>

#define ll long long
#define pii pair <int, int>
#define mp make_pair
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];

struct vt {
	ll sum;
	int minv;
	int maxv;
	int st;
	
	vt(): sum(0), minv(0), maxv(0), st(-1) {
		
	}
};

vt t[4 * maxn];

vt merg(vt a, vt b) {
	a.minv = min(a.minv, b.minv);
	a.maxv = max(a.maxv, b.maxv);
	a.sum = a.sum + b.sum;
	a.st = -1;
	return a;
}

void build(int it, int l, int r) {
	if (l == r) {
		t[it].sum = t[it].minv = t[it].maxv = v[l];
	} else {
		int m = (l + r) >> 1;
		
		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
		t[it] = merg(t[2 * it], t[2 * it + 1]);
	}
}

void sets(int it, int l, int r, int x) {
	int d = r - l + 1;
	t[it].sum = (ll)x * d;
	t[it].maxv = x;
	t[it].minv = x;
	t[it].st = x;
}

void push(int it, int l, int r) {
	if (t[it].st != -1) {
		int m = (l + r) >> 1;
		sets(2 * it, l, m, t[it].st);
		sets(2 * it + 1, m + 1, r, t[it].st);
		t[it].st = -1;
	}
}

void change(int it, int l, int r, int lm, int rm, int x) {
	if (t[it].minv >= x) {
		return;
	}
	
	if (l == r) {
		sets(it, l, r, x);
	} else if (l == lm && r == rm) {
		push(it, l, r);
		if (t[it].maxv <= x) {
			sets(it, l, r, x);
		} else {
			int m = (l + r) >> 1;
			change(2 * it, l, m, lm, m, x);
			change(2 * it + 1, m + 1, r, m + 1, rm, x);
			t[it] = merg(t[2 * it], t[2 * it + 1]);
		}
	} else {
		int m = (l + r) >> 1;
		push(it, l, r);
		
		if (rm <= m) {
			change(2 * it, l, m, lm, rm, x);
		} else if (lm > m) {
			change(2 * it + 1, m + 1, r, lm, rm, x);
		} else {
			change(2 * it, l, m, lm, m, x);
			change(2 * it + 1, m + 1, r, m + 1, rm, x);
		}
		
		t[it] = merg(t[2 * it], t[2 * it + 1]);
	}
}

int fnd(int it, int l, int r, int lm, int rm, int y) {
	if (l == r) {
		if (t[it].maxv > y) {
			return l + 1;
		}
		
		return l;
	} else if (l == lm && r == rm) {
		int m = (l + r) >> 1;
		push(it, l, r);
		
		if (t[2 * it].minv <= y) {
			return fnd(2 * it, l, m, lm, m, y);
		} else {
			return fnd(2 * it + 1, m + 1, r, m + 1, rm, y);
		}
	} else {
		int m = (l + r) >> 1;
		push(it, l, r);
		
		if (rm <= m) {
			return fnd(2 * it, l, m, lm, rm, y);
		} else if (lm > m) {
			return fnd(2 * it + 1, m + 1, r, lm, rm, y);
		} else {
			int ans = fnd(2 * it, l, m, lm, m, y);
			if (ans == m + 1) {
				ans = fnd(2 * it + 1, m + 1, r, m + 1, rm, y);
			}
			return ans;
		}
	}
}

int go(int it, int l, int r, int lm, int rm, int &y) {
	if (l == r) {
		if (t[it].maxv <= y) {
			y -= t[it].maxv;
			return 1;
		}
		
		return 0;
	} else if (l == lm && r == rm) {
		int m = (l + r) >> 1;
		push(it, l, r);
		if (t[it].sum <= y) {
			y -= t[it].sum;
			return r - l + 1;
		}
		
		int cnt = go(2 * it, l, m, lm, m, y);
		if (cnt == m - lm + 1) {
			cnt += go(2 * it + 1, m + 1, r, m + 1, rm, y);
		}
		
		return cnt;
	} else {
		int m = (l + r) >> 1;
		push(it, l, r);
		
		if (rm <= m) {
			return go(2 * it, l, m, lm, rm, y);
		} else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm, y);
		} else {
			int ans = go(2 * it, l, m, lm, m, y);
			if (ans == m - lm + 1) {
				ans += go(2 * it + 1, m + 1, r, m + 1, rm, y);
			}
			
			return ans;
		}
	}
}

mt19937 rr;

int main() {
	int n, q;
	cin >> n >> q;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	
	build(1, 0, n - 1);
	
	while (q--) {
		int tp, x, y;
		scanf("%d %d %d", &tp, &x, &y);

		x--;
		
		if (tp == 1) {
			change(1, 0, n - 1, 0, x, y);
		} else {
			int ans = 0;
			
			while (x < n) {
				int pos = fnd(1, 0, n - 1, x, n - 1, y);
				
				if (pos == n) {
					break;
				}
				
				int tot = go(1, 0, n - 1, pos, n - 1, y);
				assert(tot > 0);
				ans += tot;
				x = pos + tot;
			}
			
			printf("%d\n", ans);
		}
	}
}