#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 5;

typedef long long ll;

map<int, int> compr;
class Fenwick {
  vector<ll> tree;

public:
  Fenwick (int _length = MAX_N) : tree(_length, 0LL) {}

  void add (int pos, ll x) {
    for (int i = pos; i < (int) tree.size(); i += i & -i) {
      tree[i] += x;
    }
  }
  
  ll get (int pos) {
    ll ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }
};

// maintain the set of eels and the "special" positions
struct AugSet {
  set<pair<int, int>> eels;
  set<pair<int, int>> specs;

  int add (int x) {
    auto lb = eels.lower_bound(make_pair(x, MAX_N));
    int idx;
    if (lb == eels.begin() || prev(lb)->first != x) {
      idx = 0;
    } else {
      idx = prev(lb)->second + 1;
    }

    auto pos = eels.insert(make_pair(x, idx)).first;
    if (pos != eels.begin()) {
      auto prv = prev(pos);
      if (2 * prv->first < x) {
        specs.insert(make_pair(x, idx));
      }
    }

    if (pos != eels.end()) {
      auto nxt = next(pos);
      if (nxt != eels.end()) {
        specs.erase(*nxt);
        if (2 * x < nxt->first) {
          specs.insert(*nxt);
        }
      }
    }
    return idx;
  }

  void del (int x) {
    auto pos = prev(eels.lower_bound(make_pair(x, MAX_N)));
    auto nxt = next(pos);
    specs.erase(*pos);
    eels.erase(pos);

    if (nxt != eels.end()) {
      specs.erase(*nxt);
      if (nxt != eels.begin()) {
        auto prv = prev(nxt);
        if (2 * prv->first < nxt->first) {
          specs.insert(*nxt);
        }
      }
    }
  }
};

Fenwick prefsum;
AugSet augset;

void add (int x) {
  prefsum.add(compr[x], x);
  augset.add(x);
}

void del (int x) {
  prefsum.add(compr[x], -x);
  augset.del(x);
}

bool is_really_spec (pair<int, int> pr) {
  ll pref = prefsum.get(compr[pr.first] - 1) + (ll) pr.first * (ll) pr.second;
  return 2 * pref < pr.first;
}

int solve () {
  int ans = max(0, (int) augset.eels.size() - 1);
  for (auto pr : augset.specs) {
    if (is_really_spec(pr)) {
      ans--;
    }
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int qc;
  cin >> qc;

  vector<pair<char, int>> qs;
  for (int i = 0; i < qc; i++) {
    char op;
    int x;
    cin >> op >> x;

    qs.push_back(make_pair(op, x));
    compr[x] = 0;
  }

  int cur = 1;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = cur;
    cur++;
  }

  for (auto pr : qs) {
    if (pr.first == '+') {
      add(pr.second);
    } else {
      del(pr.second);
    }

    cout << solve() << '\n';
  }
}