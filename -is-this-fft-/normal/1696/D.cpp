#include <iostream>

using namespace std;

const int MAX_N = 3e5 + 5;

int arr [MAX_N];
pair<int, int> pmin [MAX_N];
pair<int, int> pmax [MAX_N];
pair<int, int> smin [MAX_N];
pair<int, int> smax [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];

    pmin[i] = {arr[i], i};
    pmax[i] = {arr[i], i};
    smin[i] = {arr[i], i};
    smax[i] = {arr[i], i};
  }

  for (int i = 2; i <= n; i++) {
    pmin[i] = min(pmin[i], pmin[i - 1]);
    pmax[i] = max(pmax[i], pmax[i - 1]);
  }

  for (int i = n - 1; i >= 1; i--) {
    smin[i] = min(smin[i], smin[i + 1]);
    smax[i] = max(smax[i], smax[i + 1]);
  }

  int ans = 0;
  int m = smax[1].second;
  int cur = m;
  while (cur != n) {
    ans++;
    if (smax[cur].second != cur) {
      cur = smax[cur].second;
    } else {
      cur = smin[cur].second;
    }
  }

  cur = m;
  while (cur != 1) {
    ans++;
    if (pmax[cur].second != cur) {
      cur = pmax[cur].second;
    } else {
      cur = pmin[cur].second;
    }
  }

  cout << ans << '\n';
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