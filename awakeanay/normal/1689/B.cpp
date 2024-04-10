#include <iostream>

#define int long long

const int MAXN = 1005;

int p[MAXN];
int out[MAXN];
int done[MAXN];
int n;

int search(int x) {
  if(x == n)
    return 1;
  for(int i = 0; i < n; i++) {
    if(!done[i] && p[x] != i) {
      done[i] = 1;
      out[x] = i;
      if(search(x+1))
        return 1;
      done[i] = 0;
    }
  }
  return 0;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    for(int i = 0; i < n; i++) {
      done[i] = 0;
      std::cin >> p[i];
      p[i]--;
    }

    int ans = search(0);
    if(!ans)
      std::cout << -1;
    else
      for(int j = 0; j < n; j++)
        std::cout << out[j] + 1 << " ";
    std::cout << std::endl;
  }

  return 0;
}