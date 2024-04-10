#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MAXN = 1005;

std::vector<int> g[MAXN];
std::vector<bool> used;
std::vector<int> mt;

bool try_kuhn(int v) {
  if(used[v])
    return false;
  used[v] = true;
  for(int j : g[v]) {
    if(mt[j] == -1 || try_kuhn(mt[j])) {
      mt[j] = v;
      return true;
    }
  }
  return false;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  
  std::sort(a, a+n);
  std::reverse(a, a+n);

  int k = 0;
  while(k < n && a[k]*3 > m)
    k++;

  for(int i = 0; i < k; i++) {
    for(int j = k; j < n; j++) {
      if(a[i]%a[j] == 0 && 2*a[i] + a[j] <= m)
        g[i].push_back(j);
    }
  }

  mt.assign(n, -1);
  std::vector<bool> used2(n, false);
  int match = 0;
  /*
  for(int i = 0; i < k; i++) {
    for(int j : g[i]) {
      if(mt[j] == -1) {
        mt[j] = i;
        used2[i] = true;
        match++;
        break;
      }
    }
  }
  */

  for(int i = 0; i < k; i++) {
    /*
    if(used2[i])
      continue;
    */
    used.assign(n, false);
    match += try_kuhn(i);
  }

  if(match != k) {
    std::cout << -1 << "\n";
  }
  else {
    std::cout << n-k << "\n";
    for(int i = k; i < n; i++) {
      if(mt[i] == -1)
        std::cout << 3*a[i] << " " << 2*a[i] << "\n";
      else
        std::cout << 2*a[mt[i]]+a[i] << " " << a[mt[i]]+a[i] << "\n";
    }
  }

  return 0;
}