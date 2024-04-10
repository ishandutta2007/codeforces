#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = (int) (5e5) + 7;

int cnt[N];
int last[N];
int slast[N];

int pcnt[N];
ll psum[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
    pcnt[x]++;
    psum[x] += x;
  }
  for (int i = 0; i < N; i++) {
    if (i) pcnt[i] += pcnt[i - 1];
    if (i) psum[i] += psum[i - 1];
  }
  int mda = -1;
  int tmda = -1;
  for (int i = 0; i < N; i++) {
    if (cnt[i]) {
      tmda = mda;
      mda = i;
    }
    if (cnt[i] >= 2) {
      tmda = i;
    }
    last[i] = mda;
    slast[i] = tmda;
  }
  auto as = [&] (int x, int y) {
    ll value = (ll) (1e18) + 7;
    for (int i = 0; i < N; i += y) {
      int l = i, r = min(N - 1, i + y - 1);
      if (last[r] >= x) {
        value = min(value, (ll) (last[r] / y - (last[r] - x) / y));
      }
    }
    return value;
  };
  auto ans_two = [&] (int x, int y) {
    ll best_a = (ll) (1e18) + 7;
    ll best_b = (ll) (1e18) + 7;
    for (int i = 0; i < N; i += y) {
      int l = i, r = min(N - 1, i + y - 1);
      if (last[r] >= l && last[r] >= x) {
        ll value = last[r] / y - (last[r] - x) / y;
        if (value < best_a) {
          swap(value, best_a);
        }
        if (value < best_b) {
          swap(value, best_b);
        }
      }
      if (slast[r] >= l && slast[r] >= x) {
        ll value = slast[r] / y - (slast[r] - x) / y;
        if (value < best_a) {
          swap(value, best_a);
        }
        if (value < best_b) {
          swap(value, best_b);
        }
      }
    }
    return best_a + best_b;
  };
  auto check = [&] (ll x, int y, ll s) {
    if (x >= N) {
      return false;
    }
    if (s - as(2 * x, y) >= x) {
      return true;
    }
    if (s - ans_two(x, y) >= x) {
      return true;
    }
    return false;
  };
  ll ans = 4;
  vector <int> ord_y;
  for (int y = 2; y < N; y++) {
    ord_y.push_back(y);
  }
  shuffle(ord_y.begin(), ord_y.end(), rnd);
  auto seg_sum = [&] (int l, int r) {
    return psum[r] - (l ? psum[l - 1] : 0);
  };
  auto seg_cnt = [&] (int l, int r) {
    return pcnt[r] - (l ? pcnt[l - 1] : 0);
  };
  auto get_sum = [&] (int y) {
    ll sum = 0;
    for (int i = 0; i < N; i += y) {
      int l = i, r = min(N - 1, i + y - 1);
      sum += seg_cnt(l, r) * (ll) (i / y);
    }
    return sum;
  };
  for (int y : ord_y) {
    ll s = get_sum(y);
    ll vl = max(2ll, ans / y + 1);
    if (check(vl, y, s)) {
      int vr = N;
      while (vl < vr - 1) {
        int vm = (vl + vr) / 2;
        if (check(vm, y, s)) {
          vl = vm;
        } else {
          vr = vm;
        }
      }
      ans = vl * (ll) y;
    }
  }
  cout << ans << '\n';
}