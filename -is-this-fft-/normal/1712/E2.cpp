#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<int> divs (int x) {
  vector<int> sma;
  vector<int> big;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      sma.push_back(i);
      if (i * i != x) {
        big.push_back(x / i);
      }
    }
  }

  reverse(big.begin(), big.end());
  sma.insert(sma.end(), big.begin(), big.end());
  return sma;
}

ll tc (ll x) {
  return (x * (x - 1) * (x - 2)) / 6;
}

ll pc (ll x) {
  return (x * (x - 1)) / 2;
}

struct Fenwick {
  vector<ll> tree;

public:
  Fenwick (int n) : tree(n + 5, 0) {}

  void add (int idx, ll val) {
    for (int i = idx; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  ll get (int idx) {
    ll ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }
};

ll cntf (int L, int K) {
  auto ds = divs(K);
  ds.pop_back(); // K

  int cnt = 0;
  for (int i = 0; i < (int) ds.size(); i++) {
    if (ds[i] >= L) {
      cnt++;
    }
  }

  ll ans = pc(cnt);

  if (K % 3 == 0 && K % 2 == 0 && K / 2 >= L) {
    ans++;
  }
  
  if (K % 3 == 0 && K % 5 == 0 && 2 * (K / 5) >= L) {
    ans++;
  }

  return ans;
}

void solve () {
  int L, R;
  cin >> L >> R;

  ll ans = tc(R - L + 1);
  for (int k = L + 2; k <= R; k++) {
    ans -= cntf(L, k);
  }

  cout << ans << '\n';
}

const int MAX_N = 2e5 + 5;

int L [MAX_N];
int R [MAX_N];
ll ans [MAX_N];

int cnt [MAX_N];
vector<int> add [MAX_N];
vector<int> evs [MAX_N]; // >= 0 - query

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    cin >> L[i] >> R[i];
    evs[L[i]].push_back(i);
  }
  
  Fenwick fen (MAX_N);
  for (int k = MAX_N - 1; k > 0; k--) {
    if (k % 6 == 0) {
      add[k / 2].push_back(k);
    }

    if (k % 15 == 0) {
      add[2 * (k / 5)].push_back(k);
    }

    for (int l = 2 * k; l < MAX_N; l += k) {
      cnt[l]++;
      fen.add(l, pc(cnt[l]) - pc(cnt[l] - 1));
    }

    for (auto l : add[k]) {
      fen.add(l, 1);
    }

    for (auto i : evs[k]) {
      ans[i] += tc(R[i] - L[i] + 1);
      ans[i] -= fen.get(R[i]);
    }
  }

  for (int i = 0; i < qc; i++) {
    cout << ans[i] << '\n';
  }
}