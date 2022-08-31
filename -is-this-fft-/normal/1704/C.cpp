#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  vector<int> arr (m);
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    arr[i]--;
  }
  sort(arr.begin(), arr.end());

  vector<int> segs;
  for (int i = 0; i < m - 1; i++) {
    segs.push_back(arr[i + 1] - arr[i] - 1);
  }
  segs.push_back(n + arr[0] - arr.back() - 1);
  sort(segs.begin(), segs.end(), greater<int>());

  int ans = m;
  for (int i = 0; i < m; i++) {
    int len = segs[i];
    int dead = min(len, 4 * i);
    ans += dead;
    len -= dead;

    if (len == 0) continue;
    // day 1. protect one house
    len--;
    if (len == 0) continue;
    ans++;
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