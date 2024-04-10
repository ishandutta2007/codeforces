#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  ll sum = 0;
  map<ll, int> need;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    need[x]++;
    sum += x;
  }

  vector<ll> cur = {sum};
  while (!cur.empty()) {
    ll pc = cur.back();
    cur.pop_back();

    if (need[pc]) {
      need[pc]--;
      continue;
    }

    if (pc == 1) {
      cout << "NO" << '\n';
      return;
    }

    cur.push_back(pc / 2);
    cur.push_back((pc + 1) / 2);

    if ((int) cur.size() > n) {
      cout << "NO" << '\n';
      return;
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