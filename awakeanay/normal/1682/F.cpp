#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MAXN = 200005;
const int MOD = 1000'000'007;

struct bit 
{
  std::vector<int> b;

  void add(int x, int v) {
    v %= MOD;
    x += 1;
    while(x < MAXN) {
      b[x] += v;
      b[x] %= MOD;
      x += x&-x;
    }
  }

  int sum(int x) {
    x += 1;
    int ret = 0;
    while(x > 0) {
      ret += b[x];
      ret %= MOD;
      x -= x&-x;
    }
    return ret;
  }

  int sum(int l, int r) {
    return (sum(r)-sum(l-1)+MOD)%MOD;
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;

  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int b[n];
  std::pair<int, int> help[n];
  for(int i = 0; i < n; i++) {
    std::cin >> b[i];
    if(i)
      b[i] += b[i-1];
    help[i] = {b[i], i};
  }

  std::sort(help, help+n);

  bit b1;
  bit b2;
  b1.b = b2.b = std::vector<int>(MAXN, 0);

  for(int i = 0; i < n; i++) {
    if(i) {
      int v = a[i]*(b[i-1]%MOD);
      v %= MOD;
      b2.add(i, v);
    }
    int v = a[i]*(b[i]%MOD);
    v %= MOD;
    v = (MOD-v)%MOD;
    b2.add(i, v);
  }

  int ans[q];
  int rev[n];

  std::pair<std::pair<int, int>, int> qs[q];

  for(int i = 0; i < n; i++)
    rev[help[i].second] = i;

  for(int i = 0; i < q; i++) {
    std::cin >> qs[i].first.second >> qs[i].first.first;
    qs[i].second = i;
    qs[i].first.first--; qs[i].first.second--;
    qs[i].first.first = rev[qs[i].first.first];
  }

  std::sort(qs, qs+q);

  for(int i = 0; i < n; i++)
    b[i] %= MOD;

  int ct = 0;
  for(int i = 0; i < n; i++) {
    while(ct < q && qs[ct].first.first == i) {
      int r = help[qs[ct].first.first].second;
      int l = qs[ct].first.second;
      int res = (b[r]%MOD)*b1.sum(l, r) + b2.sum(l, r);
      res %= MOD;
      res += MOD;
      res %= MOD;
      ans[qs[ct].second] = res;
      ct++;
    }

    int j = help[i].second;
    if(j+1 < n) {
      b1.add(j+1, 2*a[j+1]);
      int v = -2*b[j];
      v %= MOD;
      v += MOD;
      v %= MOD;
      b2.add(j+1, (v*a[j+1])%MOD);
    }

    int v = -2*a[j];
    v %= MOD;
    v += MOD;
    v %= MOD;
    b1.add(j, v);
    b2.add(j, (2*b[j]*a[j])%MOD);
  }

  for(int i = 0; i < q; i++)
    std::cout << ans[i] << "\n";

  return 0;
}