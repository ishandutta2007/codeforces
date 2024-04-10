#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 200000;
int const buckets = 450;

int sum[1 + buckets][1 + nmax];
int active[1 + nmax];

int x[5 + nmax], y[5 + nmax], last[5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    std::cin >> x[i] >> y[i];
  int total = 0;

  for(int i = 1;i <= m; i++) {
    int op, k;
    std::cin >> op >> k;
    int sz = x[k] + y[k];
    active[i] += active[i - 1];
    if(op == 1) {
      total++;
      last[k] = i;
      if(sz <= buckets) {
        for(int j = 0; j < x[k]; j++)
          sum[sz][(i + j) % sz]++;
      } else {
        int ptr = i;
        while(ptr <= m) {
          active[ptr]++;
          if(ptr + x[k] <= m)
            active[ptr + x[k]]--;
          ptr += x[k] + y[k];
        }
      }
    } else {
      total--;
      if(sz <= buckets) {
        for(int j = 0; j < x[k]; j++)
          sum[sz][(last[k] + j) % sz]--;
      } else {
        int ptr = last[k];
        while(ptr <= m) {
          if(i <= ptr)
            active[ptr]--;
          else
            active[i]--;
          if(ptr + x[k] <= m) {
            if(i <= ptr + x[k])
              active[ptr + x[k]]++;
            else
              active[i]++;
          }
          ptr += x[k] + y[k];
        }
      }
    }
    int result = active[i];
    for(int j = 1; j <= buckets; j++)
      result += sum[j][i % j];
    std::cout << total - result << '\n';
  }
  return 0;
}