#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e15;
const ll MOD2 = 998244353;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int M = 1e5;
const int N = 1e6 + 10;

struct Query {
  int l;
  int r;
  int i;
  ll ans;
};

struct State {
  ll cur_sum = 0;
  int l = 0;
  int r = 0;
  std::array<ll, N> cnt = {0};

  void inc_right(const vector<ll>& a) {
    cur_sum -= cnt[a[r]] * cnt[a[r]] * a[r];
    cnt[a[r]]++;
    cur_sum += cnt[a[r]] * cnt[a[r]] * a[r];
    r++;
  }

  void dec_right(const vector<ll>& a) {
    cur_sum -= cnt[a[r - 1]] * cnt[a[r - 1]] * a[r - 1];
    cnt[a[r - 1]]--;
    cur_sum += cnt[a[r - 1]] * cnt[a[r - 1]] * a[r - 1];
    r--;
  }

  void inc_left(const vector<ll>& a) {
    cur_sum -= cnt[a[l]] * cnt[a[l]] * a[l];
    cnt[a[l]]--;
    cur_sum += cnt[a[l]] * cnt[a[l]] * a[l];
    l++;
  }

  void dec_left(const vector<ll>& a) {
    cur_sum -= cnt[a[l - 1]] * cnt[a[l - 1]] * a[l - 1];
    cnt[a[l - 1]]++;
    cur_sum += cnt[a[l - 1]] * cnt[a[l - 1]] * a[l - 1];
    l--;
  }
};

class Solver {
public:
  void solve() {
    int n, t;
    cin >> n >> t;
    a.resize(n);
    for (auto& e : a) cin >> e;

    qs.resize(t);
    for (int i = 0; i < t; ++i) {
      cin >> qs[i].l >> qs[i].r;
      qs[i].l--;
      qs[i].i = i;
      qs[i].ans = 0;
    }

    int block_size = sqrt(n);
    auto count_block_id = [block_size](auto& q) {return q.l / block_size;};

    sort(qs.begin(), qs.end(), [count_block_id](auto& l, auto& r) {
        int l_block = count_block_id(l);
        int r_block = count_block_id(r);
        return tuple(l_block, l.r) < tuple(r_block, r.r);
    });

    State state;
    for (auto& q : qs) {
      while (state.r < q.r) state.inc_right(a);
      while (state.r > q.r) state.dec_right(a);
      while (state.l < q.l) state.inc_left(a);
      while (state.l > q.l) state.dec_left(a);
      q.ans = state.cur_sum;
    }

    sort(qs.begin(), qs.end(), [](auto& l, auto& r) {return l.i < r.i;});
    for (const auto& q : qs) {
      cout << q.ans << "\n";
    }

  }

private:


  vector<ll> a;
  vector<Query> qs;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
}