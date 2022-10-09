#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 30000;
int v[5 + nmax], fib[5 + nmax];
int vreal[5 + nmax];
int id[5 + nmax], sol[5 + nmax], l[5+ nmax], r[5 + nmax];

int main() {
  int n, modulo;
  std::cin >> n >> modulo;
  fib[0] = 1;
  fib[1] = 1;
  for(int i = 2;i <= n; i++)
    fib[i] = (fib[i - 2] + fib[i - 1]) % modulo;

  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    id[i] = i;
  std::sort(id + 1, id + n +1 , [&](int x, int y) {
      return v[x] < v[y];
  });

  std::sort(v + 1, v + n + 1);
  for(int i = 1;i <= n; i++)
    vreal[i] = v[i];
  for(int i = 1; i <= n; i++)
    v[i] = v[i] % modulo;

  int q;
  std::cin >> q;
  
  for(int i = 1;i <= q; i++)
    std::cin >> l[i] >> r[i];

  for(int i = 1; i <= q; i++) {
    int ptr = 0, result = 0, last = -1;
    for(int j = 1;j <= n; j++) {
      if(l[i] <= id[j] && id[j] <= r[i] && last != vreal[j]) {
        result = (result + v[j] * fib[ptr++]) % modulo;
        last = vreal[j];
      }
    }
    sol[i] = result;
  }
  for(int i = 1;i <= q; i++)
    std::cout << sol[i] << '\n';

  return 0;
}