#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

void solve() {
  int n;
  cin >> n;
  set<int> s;
  vector<int> a(n);
  vector<int> a_init(n);
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
    a_init[i] = a[i];
    if (s.count(a[i])) {
      a[i] = -1;
      b.push_back(i);
    }
    s.insert(a[i]);
  }

  set<int> t;
  for (int i = 0; i < n; ++i) {
    if (!s.count(i)) {
      t.insert(i);
    }
  }

  if (t.size() == 1u && b.size() == 1u && *t.begin() == b[0]) {
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
      if (a_init[i] == a_init[b[0]] && i != b[0]) {
        ptr = i;
        break;
      }
    }
    b.push_back(ptr);
    t.insert(a[ptr]);
  }

  for (int i = (int)b.size() - 1; i >= 2; --i) {
    auto it = t.begin();
    if (b[i] == *it) ++it;
    a[b[i]] = *it;
    t.erase(it);
    b.pop_back();
  }

  if (b.size() == 1u) {
    assert(t.size() == 1u);
    a[b[0]] = *t.begin();
  } else if (b.size() == 2u) {
    int t1 = *t.begin();
    int t2 = *(next(t.begin()));
    if (b[0] != t1 && b[1] != t2) {
      a[b[0]] = t1;
      a[b[1]] = t2;
    } else {
      a[b[0]] = t2;
      a[b[1]] = t1;
    }
  } else {
    assert(t.empty());
  }

  int answer = 0;
  for (int i = 0; i < n; ++i) {
    answer += (a[i] == a_init[i]);
  }
  cout << answer << "\n";
  for (auto x: a) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}