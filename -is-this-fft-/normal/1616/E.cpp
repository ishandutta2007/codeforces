#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

struct Fenwick {
  vector<ll> tree;

  Fenwick (int _n) : tree(_n + 5, 0LL) {}

  void add (int idx, ll val) {
    idx++;
    for (int i = idx; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  ll get (int idx) {
    idx++;
    ll ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }
};

const ll INF = 1e18 + 5;
const int MAX_N = 1e5 + 5;
const int ALPHA = 250;

vector<int> pos [ALPHA];

void solve () {
  for (char c = 'a'; c <= 'z'; c++) {
    pos[c].clear();
  }

  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  for (int i = n - 1; i >= 0; i--) {
    pos[s[i]].push_back(i);
  }

  set<int> ign;
  int sptr = 0;
  ll ans = INF, cur = 0;
  Fenwick fen (n);
  for (int i = 0; i < n; i++) {
    bool skip = false;
    if (s[sptr] < t[i]) {
      ans = min(ans, cur);
      break;
    } else {
      ll mind = INF;
      for (char c = 'a'; c < t[i]; c++) {
        while (!pos[c].empty() && pos[c].back() < sptr) {
          pos[c].pop_back();
        }

        if (!pos[c].empty()) {
          mind = min(mind, (ll) pos[c].back());
        }
      }

      mind += fen.get(mind);
      if (mind != INF) {
        ans = min(ans, cur + mind - sptr);
      }
    }

    if (s[sptr] > t[i]) {
      // make them equal
      while (!pos[t[i]].empty() && pos[t[i]].back() < sptr) {
        pos[t[i]].pop_back();
      }

      if (pos[t[i]].empty()) {
        break;
      }

      skip = true;
      int bk = pos[t[i]].back();
      pos[t[i]].pop_back();
      cur += bk + fen.get(bk) - sptr;
      fen.add(bk, -1);
      ign.insert(bk);
    }

    if (!skip) {
      sptr++;
      while (ign.count(sptr)) {
        fen.add(sptr, 1);
        sptr++;
      }
    }
  }

  if (ans == INF) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}