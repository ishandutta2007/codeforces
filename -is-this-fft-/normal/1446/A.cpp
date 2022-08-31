#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll arr [MAX_N];

void solve () {
  int n;
  ll W;
  cin >> n >> W;

  ll mid = (W + 1) / 2;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> ans;
  ll cur = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] <= W && arr[i] >= mid) {
      cout << 1 << '\n' << i << '\n';
      return;
    }

    if (cur + arr[i] <= W) {
      cur += arr[i];
      ans.push_back(i);
    }
  }

  if (cur < mid) {
    cout << -1 << '\n';
    return;
  }

  cout << (int) ans.size() << '\n';
  for (int u : ans) {
    cout << u << " ";
  }
  cout << '\n';
  return;
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}