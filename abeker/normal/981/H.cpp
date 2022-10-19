#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int md = 998244353;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

namespace ntt {
  int base = 1;
  vector<int> roots = {0, 1};
  vector<int> rev = {0, 1};
  int max_base = -1;
  int root = -1;

  void init() {
    int tmp = md - 1;
    max_base = 0;
    while (tmp % 2 == 0) {
      tmp /= 2;
      max_base++;
    }
    root = 2;
    while (true) {
      if (power(root, 1 << max_base) == 1) {
        if (power(root, 1 << (max_base - 1)) != 1) {
          break;
        }
      }
      root++;
    }
  }

  void ensure_base(int nbase) {
    if (max_base == -1) {
      init();
    }
    if (nbase <= base) {
      return;
    }
    assert(nbase <= max_base);
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      int z = power(root, 1 << (max_base - 1 - base));
      for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        roots[(i << 1) + 1] = mul(roots[i], z);
      }
      base++;
    }
  }

  void fft(vector<int> &a) {
    int n = a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int k = 1; k < n; k <<= 1) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          int x = a[i + j];
          int y = mul(a[i + j + k], roots[j + k]);
          a[i + j] = x + y - md;
          if (a[i + j] < 0) a[i + j] += md;
          a[i + j + k] = x - y + md;
          if (a[i + j + k] >= md) a[i + j + k] -= md;
        }
      }
    }
  }

  vector<int> multiply(vector<int> a, vector<int> b, int eq = 0) {
    int need = a.size() + b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    fft(a);
    if (eq) b = a; else fft(b);
    int inv_sz = inv(sz);
    for (int i = 0; i < sz; i++) {
      a[i] = mul(mul(a[i], b[i]), inv_sz);
    }
    reverse(a.begin() + 1, a.end());
    fft(a);
    a.resize(need);
    return a;
  }

  vector<int> square(vector<int> a) {
    return multiply(a, a, 1);
  }
};

int N, K;
vector <int> E[MAXN];
int subtree[MAXN];
int down[MAXN];
vector <int> glob;
int choose[MAXN];
int ans;

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
}

int calc(int x, int p) {
	subtree[x] = 1;
	for (auto it : E[x])
		if (it != p)
			subtree[x] += calc(it, x);
	return subtree[x];
}

vector <int> dac(int lo, int hi) {
	if (lo >= hi)
		return {1};
	if (hi - lo == 1)
		return {glob[lo], 1};
	int mid = (lo + hi) / 2;
	return ntt::multiply(dac(lo, mid), dac(mid, hi));
}

void horner(vector <int> &P, int zero) {
	int sz = P.size();
	vector <int> Q = P;
	P[sz - 1] = 0;
	for (int i = sz - 2; i >= 0; i--) {
		P[i] = Q[i + 1];
		sub(P[i], mul(zero, P[i + 1]));
	}
	P.pop_back();
}

int get(vector <int> P) {
	reverse(P.begin(), P.end());
	int res = 0;
	for (int i = 0; i < min((int)P.size(), K + 1); i++)
		add(res, mul(choose[i], P[i]));
	return res;
}

int dfs(int x, int p) {
	unordered_map <int, int> tot;
	vector <int> curr;
	for (auto it : E[x])
		if (it != p) {
			add(tot[subtree[it]], dfs(it, x));
			curr.push_back(subtree[it]);
		}
	if (x > 1)
		curr.push_back(N - subtree[x]);
	
	glob = curr;
	vector <int> poly = dac(0, (int)glob.size());
	
	vector <int> d = poly;
	if (x > 1)
		horner(d, N - subtree[x]);
	down[x] = get(d);
	
	int sum = 0;
	for (auto it : tot) {
		vector <int> tmp = poly;
		horner(tmp, it.first);
		add(ans, mul(get(tmp), it.second));
		add(sum, it.second);
	}
	
	sub(ans, mul(down[x], sum));
	add(sum, down[x]);
	
	return sum;
}

int solve() {
	if (K == 1)
		return (long long)N * (N - 1) / 2 % md;
		
	calc(1, 0);
	
	choose[0] = 1;
	for (int i = 1; i <= K; i++)
		choose[i] = mul(choose[i - 1], K - i + 1);
		
	dfs(1, 0);
		
	for (int i = 1; i <= N; i++) {
		add(ans, mul(down[i], down[i - 1]));
		add(down[i], down[i - 1]);
	}

	return ans;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}