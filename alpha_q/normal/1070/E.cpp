#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int N = 200010;

vector <ll> v;
vector <int> id[N];
bitset <N> ya;
int tt, n, m;
ll t, p[N], f1[N], f2[N];

void update (int pos) {
  ll val = p[pos];
  while (pos < N) ++f1[pos], f2[pos] += val, pos += pos & -pos; 
}

int get (int pos) {
  int ret = 0;
  while (pos > 0) ret += f1[pos], pos -= pos & -pos;
  return ret;
}

ll query (int pos) {
  ll ret = 0;
  while (pos > 0) ret += f2[pos], pos -= pos & -pos;
  return ret;
}

ll last (int at, int cnt) {
  if (cnt == 0) cnt = m;
  int lo = 1, hi = at, tot = get(at);
  while (lo < hi) {
    int mid = lo + hi + 1 >> 1;
    if (tot - get(mid - 1) < cnt) hi = mid - 1;
    else lo = mid;
  }
  return query(at) - query(lo - 1);
}

int main() {
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d %d %lld", &n, &m, &t);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", p + i);
      v.push_back(p[i]);
      id[p[i]].push_back(i);
      f1[i] = f2[i] = 0;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll sum = 0;
    int ptr = n, tot = 0;
    int mxWork = 0, ans = 1;
    for (ll d : v) {
      for (int idx : id[d]) {
        if (idx <= ptr) {
          update(idx);
          sum += 2LL * d;
          ++tot, ya[idx] = 1;
        }
      }
      // cout << " " << tot << " " << d << " " << sum << endl;
      while (ptr > 0) {
        ll cost = sum - last(ptr, tot % m);
        // cout << cost << endl;
        if (cost > t) {
          if (ya[ptr]) {
            sum -= 2LL * p[ptr];
            --tot;
          } --ptr;
        } else break;
      }
      if (tot > mxWork) {
        mxWork = tot;
        ans = d;
      }
    }
    printf("%d %d\n", mxWork, ans);
    for (int i = 1; i <= n; ++i) {
      ya[i] = 0;
      id[p[i]].clear();
    }
    v.clear();
  }
  return 0;
}