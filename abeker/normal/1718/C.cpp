#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int prime[MAXN];

void sieve() {
  for (int i = 2; i < MAXN; i++)
    if (!prime[i])
      for (int j = i; j < MAXN; j += i)
        if (!prime[j])
          prime[j] = i;
}

vector <int> get(int x) {
  vector <int> res;
  for (int y = x; y > 1;) {
    int tmp = prime[y];
    while (!(y % tmp))
      y /= tmp;
    res.push_back(x / tmp);
  }
  return res;
}

void solve() {
  int N, Q;
  scanf("%d%d", &N, &Q);
  vector <int> a(N);
  vector <int> divs = get(N);
  int sz = divs.size();
  vector <vector <ll>> sums(sz);
  vector <multiset <ll>> all(sz);
  for (int i = 0; i < sz; i++)
    sums[i].resize(divs[i]);
  auto update = [&](int pos, int val) {
    int diff = val - a[pos];
    a[pos] = val;
    for (int i = 0; i < sz; i++) {
      ll &ref = sums[i][pos % divs[i]];
      all[i].erase(all[i].find(ref));
      ref += diff;
      all[i].insert(ref);
    }
  };
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j < sz; j++)
      sums[j][i % divs[j]] += a[i];
  }
  for (int i = 0; i < sz; i++)
    for (auto it : sums[i])
      all[i].insert(it);
  auto query = [&]() {
    ll res = 0;
    for (int i = 0; i < sz; i++)
      res = max(res, (ll)divs[i] * *all[i].rbegin());
    printf("%lld\n", res);
  };
  query();
  while (Q--) {
    int p, x;
    scanf("%d%d", &p, &x);
    update(--p, x);
    query();
  }
}

int main() {
  sieve();
  int tc;
  scanf("%d", &tc);
  while (tc--)
    solve();
  return 0;
}