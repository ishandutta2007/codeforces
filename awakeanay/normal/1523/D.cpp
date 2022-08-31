#include <iostream>
#include <chrono>
#include <vector>
#include <random>

#define int long long

const int RM = 50;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int ans = 0, best = 0;

  int n, m, p;
  std::cin >> n >> m >> p;

  std::vector<int> val(n, 0);

  for(int i = 0; i < n; i++) {
    for(int j = m-1; j >= 0; j--) {
      char c;
      std::cin >> c;
      if(c == '1')
        val[i] += (1ll << j);
    }
  }

  std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
  int lim = n-n/2;

  for(int it = 0; it < RM; it++) {
    int cn = gen()%n;

    if(val[cn] == 0)
      continue;

    std::vector<int> cs;
    for(int j = 0; j < m; j++) {
      if((val[cn] >> j)&1ll)
        cs.push_back(j);
    }

    int N = cs.size();
    int M = (1 << N);

    std::vector<int> A(M, 0), F(M, 0);

    for(int i = 0; i < n; i++) {
      int cval = M-1;
      for(int j = 0; j < N; j++) {
        if((val[i] >> cs[j])&1ll) {
          cval -= (1ll << j);
        }
      }
      A[cval]++;
    }

    // Code for SOS DP from https://codeforces.com/blog/entry/45223
    for(int i = 0; i<(1<<N); ++i)
      F[i] = A[i];
    for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
      if(mask & (1<<i))
        F[mask] += F[mask^(1<<i)];
    }

    for(int i = 0; i < M; i++) {
      if(F[i] >= lim) {
        int count = 0;
        int cval = 0;
        for(int j = 0; j < N; j++) {
          if(((i >> j)&(1ll)) == 0) {
            cval += (1ll << cs[j]);
            count++;
          }
        }

        if(count > ans) {
          ans = count;
          best = cval;
        }
      }
    }
  }

  for(int i = m-1; i >= 0; i--) {
    if((best >> i)&1ll)
      std::cout << 1;
    else
      std::cout << 0;
  }
  
  std::cout << std::endl;

  return 0;
}