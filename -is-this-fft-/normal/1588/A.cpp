#include <iostream>
#include <map>

using namespace std;

void solve () {
  int n;
  cin >> n;

  map<int, int> ac, bc;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    ac[x]++;
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    bc[x]++;
  }

  for (auto pr : bc) {
    int val = pr.first, cnt = pr.second;

    int rem = min(cnt, ac[val - 1]);
    cnt -= rem;

    if (ac[val] < cnt) {
      cout << "NO" << '\n';
      return;
    }

    ac[val] -= cnt;
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