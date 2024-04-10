#include <bits/stdc++.h>

const long long INF = std::numeric_limits<long long>::max() / 2;

const int N = 100000, L = 17;

int mu[N + 1], phi[N + 1];
long long sum[N + 1];
std::vector<int> d[N + 1];

long long f[L + 1][N + 1];

long long calc(int l, int r) {
  static int nl = 1, nr = 1;
  static long long res = 1;

  auto calcL = [&]() {
    return sum[nr / nl];
  };

  auto calcR = [&]() {
    long long res = 0;
    for (int x : d[nr]) {
      if (x >= nl) {
        res += phi[nr / x];
      }
    }
    return res;
  };

  while (nl > l) {
    --nl;
    res += calcL();
  }
  while (nr < r) {
    ++nr;
    res += calcR();
  }
  while (nl < l) {
    res -= calcL();
    ++nl;
  }
  while (nr > r) {
    res -= calcR();
    --nr;
  }
  return res;
}

void solve(int k, int l, int r, int L, int R) {
  if (l > r) {
    return;
  }
  int mid = (l + r) >> 1;
  int p = mid;
  f[k][mid] = f[k - 1][mid];
  for (int i = std::min(mid - 1, R); i >= L; --i) {
    long long v = f[k - 1][i] + calc(i + 1, mid);
    if (v < f[k][mid]) {
      f[k][mid] = v;
      p = i;
    }
  }
  solve(k, l, mid - 1, L, p);
  solve(k, mid + 1, r, p, R);
}

void init() {
  for (int i = 1; i <= N; ++i) {
    mu[i] += i == 1;
    phi[i] += i;
    sum[i] = sum[i - 1] + phi[i];
    for (int j = i + i; j <= N; j += i) {
      mu[j] -= mu[i];
      phi[j] -= phi[i];
    }
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = i; j <= N; j += i) {
      d[j].push_back(i);
    }
  }
  for (int i = 1; i <= N; ++i) {
    f[0][i] = INF;
  }
  for (int k = 1; k <= L; ++k) {
    solve(k, 0, N, 0, N);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  init();

  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    if (k > L) {
      std::cout << n << "\n";
    } else {
      std::cout << f[k][n] << "\n";
    }
  }
}