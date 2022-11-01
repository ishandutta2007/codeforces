#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

string a[N];
const string lck = "lock";
const string unlck = "unlock";
set<pair<int, int>> all, good;

string get_color() {
  if (good.empty()) return "blue";
  return a[prev(good.end())->second - 1];
}

bool is_good(int l, int r) {
  return l + 1 < r && a[l] == unlck;
}

bool is_good(pair<int, int> p) {
  return is_good(p.first, p.second);
}

void process(int pos, string new_val) {
  if (a[pos] == lck || a[pos] == unlck) {
    auto it2 = all.lower_bound({pos, -INF});
    auto it1 = prev(it2);
    if (is_good(*it2)) { good.erase(*it2); }
    if (is_good(*it1)) { good.erase(*it1); }
    pair<int, int> new_el = {it1->first, it2->second};
    all.erase(it1);
    all.erase(it2);
    all.insert(new_el);
    if (is_good(new_el)) {
      good.insert(new_el);
    }
  }
  a[pos] = new_val;
  if (new_val == lck || new_val == unlck) {
    auto it = prev(all.lower_bound({pos, INF}));
    auto p = *it;
    if (is_good(p)) { good.erase(p); }
    all.erase(p);
    pair<int, int> p1 = {p.first, pos};
    pair<int, int> p2 = {pos, p.second};
    all.insert(p1);
    all.insert(p2);
    if (is_good(p1)) good.insert(p1);
    if (is_good(p2)) good.insert(p2);
  }
}

void solve() {
  int n;
  cin >> n;
  a[0] = unlck;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  a[n + 1] = lck;

  int cur = 0;
  for (int i = 1; i <= n + 1; ++i) {
    if (a[i] == lck || a[i] == unlck) {
      pair<int, int> tmp = {cur, i};
      all.insert(tmp);
      if (is_good(cur, i)) {
        good.insert(tmp);
      }
      cur = i;
    }
  }

  cout << get_color() << "\n";
  int q;
  cin >> q;
  while (q--) {
    int id;
    string s;
    cin >> id >> s;
    process(id, s);
    cout << get_color() << "\n";
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}