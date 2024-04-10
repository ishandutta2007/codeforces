#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  set<ll> seen;
  vector<ll> reduced;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    seen.insert(x);
    if (x != 0) {
      reduced.push_back(x);
    }
  }

  if ((int) reduced.size() > 4) {
    cout << "NO" << '\n';
    return;
  }

  if (seen.count(0)) {
    reduced.push_back(0);
  }

  int m = reduced.size();
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      for (int k = j + 1; k < m; k++) {
        if (!seen.count(reduced[i] + reduced[j] + reduced[k])) {
          cout << "nO" << '\n';
          return;
        }
      }
    }
  }

  cout << "YES" << '\n';
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