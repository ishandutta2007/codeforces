#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 2000;
int const modulo = 998244353;

class FenwickTree{
  private:
    std::vector<int> aib;
    int n;
  public:
    FenwickTree(int n_) {
      n = n_;
      aib.resize(1 + n);
    }
    void clear() {
      for(int i = 1;i <= n; i++)
        aib[i] = 0;
    }

    void update(int pos, int val) {
      for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
        aib[x] += val;
    }
    int query(int pos) {
      int result = 0;
      for(int x = pos; 0 < x; x = (x & (x - 1)))
        result += aib[x];
      return result;
    }
};

int fact[5 + nmax];
int dp[5 + nmax][5 + nmax];
int powp[5 + nmax];
int frec[5 + nmax];

void precompute(int n) {
  fact[0] = 1;
  for(int i = 1;i <= n; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
  for(int i = 1; i <= n; i++) 
    dp[i][0] = fact[i];
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
      if(1 < j)
        dp[i][j] = (dp[i][j] + 1LL * (j - 1) * dp[i - 1][j - 2]) % modulo;
      dp[i][j] = (dp[i][j] + 1LL * (i - j) * dp[i - 1][j - 1]) % modulo;
    }
  }
  powp[0] = 1;
  for(int i = 1;i <= n; i++)
    powp[i] = 1LL * powp[i - 1] * dp[n][n] % modulo;
}

int prev[5 + nmax], v[5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  precompute(n);
  FenwickTree aib(n), aib2(n);

  int result = 0;
  for(int step = 1;step <= n; step++) {
    aib.clear();
    aib2.clear();

    for(int i = 1;i <= n; i++)
      std::cin >> v[i];

    for(int i = 1;i <= n; i++) {
      aib.update(i, 1);
      aib2.update(i, 1);
    }

    for(int i = 1; i <= n; i++)
      frec[i] = 2;

    if(step == 1) {
      for(int i = 1;i <= n; i++) {
        result = (result + 1LL * aib.query(v[i] - 1) * fact[n - i] % modulo * powp[n - step]) % modulo;
        aib.update(v[i], -1);
      }
    } else {
      int common = n;

      for(int i = 1;i <= n; i++) {
        frec[prev[i]]--;
        if(frec[prev[i]] == 1) {
          common--;
          aib2.update(prev[i], -1);
        }

        int common2 = aib2.query(v[i] - 1);
        int total = aib.query(v[i] - 1);
        if(frec[prev[i]] == 1 && prev[i] < v[i])
          total--;
        
        if(0 < common2)
          result = (result + 1LL * common2 * dp[n - i][common - 1] % modulo * powp[n - step]) % modulo;
        result = (result + 1LL * (total - common2) * dp[n - i][common] % modulo * powp[n - step]) % modulo;
        
        frec[v[i]]--;
        if(frec[v[i]] == 1) {
          common--;
          aib2.update(v[i], -1);
        }
        aib.update(v[i], -1);
      }
    }

    for(int i = 1;i <= n; i++)
      prev[i] = v[i];
  }
  std::cout << result << '\n';
  return 0;
}