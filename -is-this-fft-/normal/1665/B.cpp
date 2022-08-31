#include <iostream>
#include <map>

using namespace std;

void solve () {
  int n;
  cin >> n;

  int maxcnt = 0;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cnt[x]++;
    maxcnt = max(maxcnt, cnt[x]);
  }

  int swapc = n - maxcnt;
  int clonec = 0;
  int cur = maxcnt;
  while (cur < n) {
    cur *= 2;
    clonec++;
  }

  cout << swapc + clonec << '\n';
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