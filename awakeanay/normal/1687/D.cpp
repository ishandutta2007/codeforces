#include <iostream>
#include <algorithm>

#define int long long

const int MAXN = 2000006;

int a[MAXN];
int l[MAXN];
int r[MAXN];
int n;

int check(int k) {
  int u = std::lower_bound(r, r+MAXN, a[0]+k)-r;

  int last = 0;
  int ret = 0;

  while(last < n) {
    if(a[last]+k < l[u])
      ret = std::max(ret, l[u]-k-a[last]);

    if(ret > 0)
      return ret;

    last = std::upper_bound(a, a+n, r[u]-k)-a;

    u++;
  }

  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;

  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  l[0] = r[0] = 0;
  for(int j = 1; j < MAXN; j++) {
    l[j] = l[j-1] + 2*j-1;
    r[j] = l[j] + j;
  }

  int cur = 0;
  int add;
  while(add = check(cur))
    cur += add;

  std::cout << cur << std::endl;

  return 0;
}