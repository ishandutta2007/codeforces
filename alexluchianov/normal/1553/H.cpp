#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 19;
int v[1 << nmax];

struct Info{
  int smin;
  int pref;
  int suff;
} dp[1 << nmax];

int main() {
  int n, k;
  std::cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    int val;
    std::cin >> val;
    v[val] = 1;
  }
  for(int i = 0; i < (1 << k); i++)
    if(v[i] == 1) {
      dp[i] = {(1 << k), 0, 0};
    } else {
      dp[i] = {(1 << k), (1 << k), (1 << k)};
    }

  for(int jump = 2; jump <= (1 << k); jump *= 2) {
    int halfjump = jump / 2;
    for(int i = 0; i < (1 << k); i += jump) {
      for(int j = i; j < i + halfjump; j++) {
        Info a = dp[j], b = dp[j + halfjump];
        dp[j].smin = std::min(std::min(a.smin, b.smin),
                              a.suff + b.pref + 1);
        dp[j].pref = std::min(a.pref, halfjump + b.pref);
        dp[j].suff = std::min(a.suff + halfjump, b.suff);

        dp[j + halfjump].smin = std::min(std::min(a.smin, b.smin),
                                    a.pref + b.suff + 1);
        dp[j + halfjump].pref = std::min(b.pref, halfjump + a.pref);
        dp[j + halfjump].suff = std::min(a.suff, halfjump + b.suff);
      }
    }
  }

  for(int i = 0; i < (1 << k); i++)
    std::cout << dp[i].smin << " ";
  std::cout << '\n';
  return 0;
}