#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll vol [MAX_N];

ll cdiv (ll a, ll b) {
  return (a + b - 1) / b;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  ll tot = 0;
  for (int i = 0; i < n; i++) {
    cin >> vol[i];
    tot += vol[i];
  }

  set<pair<ll, int>> ds;
  ll cmx = 0, cpref = 0;
  for (int i = 0; i < n; i++) {
    // time taken with i + 1 pipes
    ll cur = max(cmx, cdiv(tot, i + 1));
    ds.insert({cur, -i});
    
    cpref += vol[i];
    cmx = max(cmx, cdiv(cpref, i + 1));
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    ll t;
    cin >> t;

    auto it = ds.upper_bound({t, 1});
    if (it == ds.begin()) {
      cout << -1 << '\n';
    } else {
      cout << - prev(it)->second + 1 << '\n';
    }
  }
}