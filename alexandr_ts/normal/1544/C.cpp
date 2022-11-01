#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

void process(multiset<int>& a1, multiset<int>& a2, ll& sum) {
  if (!a2.empty()) {
    auto it = prev(a2.end());
    a1.insert(*it);
    sum += *it;
    a2.erase(it);
  }
  int n = a1.size() + a2.size();
  int k = n / 4;
  while ((int)a1.size() > n - k) {
    int val = *a1.begin();
    sum -= val;
    a1.erase(a1.begin());
    a2.insert(val);
  }
}


void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto& x: a) cin >> x;
  for (auto& x: b) cin >> x;
  multiset<int> a1, a2, b1, b2;
  ll suma = 0, sumb = 0;
  for (auto x: a) {
    a1.insert(x);
    suma += x;
  }
  for (auto x: b) {
    b1.insert(x);
    sumb += x;
  }

  for (int i = 0;; ++i) {
    process(a1, a2, suma);
    process(b1, b2, sumb);
    if (suma >= sumb) {
      cout << i << "\n";
      return;
    }
    a1.insert(100);
    suma += 100;
    b1.insert(0);
  }
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