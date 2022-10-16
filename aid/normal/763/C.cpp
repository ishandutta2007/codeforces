#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n, mod;
int a[maxn];

pair<int, int> gcd(int a, int b) {
	if (!b) {
		return make_pair(1, 0);
	}
	pair<int, int> p = gcd(b, a % b);
	return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
	int res = gcd(x, mod).first;
	if (res < 0) {
		res += mod;
	}
	return res;
}

int mul(int a, int b) {
	return (long long) a * b % mod;
}

void add(int &a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int read() {
  if (scanf("%d%d", &mod, &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
  	scanf("%d", &a[i]);
  }
  return true;
}

int b[2][maxn];
int used[2 * maxn];

void solve() {
	if (n == mod) {
		printf("0 1\n");
		return;
	}
	bool rev = false;
	if (n * 2 > mod) {
		for (int i = 0; i < mod; i++) {
			used[i] = false;
		}
		for (int i = 0; i < n; i++) {
			used[a[i]] = true;
		}
		n = 0;
		for (int i = 0; i < mod; i++) {
			if (!used[i]) {
				a[n++] = i;
			}
		}
		rev = true;
	}
	if (n == 1) {
		if (rev) {
			printf("%d %d\n", sum(a[0], 1), 1);
			return;
		}
		printf("%d %d\n", a[0], 1);
		return;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = sum(a[j], mod - a[i]);
		}
		sort(b[i], b[i] + n);
	}
	int k = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && b[1][j] < b[0][i]) {
			j++;
		}
		if (j < n && b[1][j] == b[0][i]) {
			k++;
			j++;
		}
	}
	k = n - k;
	if (!k) {
		printf("-1\n");
		return;
	}
	int d = mul(sum(a[1], mod - a[0]), inv(k));
	int x = -1;
	int cnt = 0;
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int prv = sum(a[i], mod - d);
		int pos = lower_bound(a, a + n, prv) - a;
		if (pos == n || a[pos] != prv) {
			x = a[i];
			cnt++;
		}
	}
	if (cnt > 1) {
		printf("-1\n");
		return;
	}
	if (cnt == 0) {
		x = a[0];
	}
	if (rev) {
		add(x, mul(n, d));
	}
	printf("%d %d\n", x, d);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}