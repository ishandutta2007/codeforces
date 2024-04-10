#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

void solve () {
  int n, C;
  cin >> n >> C;

  vector<int> arr;
  set<int> seen;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (!seen.count(x)) {
      arr.push_back(x);
      seen.insert(x);
    }
  }

  sort(arr.begin(), arr.end());
  n = arr.size();

  vector<int> cnt (C + 1, 0);
  for (int y : arr) {
    for (int i = 0; i < n && y * (ll) arr[i] <= C; i++) {
      int a = arr[i];
      cnt[y * a]++;
      if (y * (a + 1) <= C) {
        cnt[y * (a + 1)]--;
      }
    }
  }

  for (int i = 1; i <= C; i++) {
    cnt[i] += cnt[i - 1];
  }

  int need = 0;
  for (int y : arr) {
    need++;
    if (cnt[y] < need) {
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