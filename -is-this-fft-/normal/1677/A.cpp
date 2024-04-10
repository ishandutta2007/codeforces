#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i]--;
  }

  ll ans = 0;
  vector<vector<ll>> dpb (n, vector<ll> (n, 0));
  vector<ll> dpc (n, 0);
  for (int i = 0; i < n; i++) {
    // consider as d
    for (int j = arr[i] + 1; j < n; j++) {
      ans += dpc[j];
    }

    // consider as c
    for (int j = 0; j < n; j++) {
      if (arr[i] == 0)
        continue;
      
      dpc[j] += dpb[j][arr[i] - 1];
    }

    // consider as b
    for (int j = 0; j < i; j++) {
      dpb[arr[i]][arr[j]]++;
    }

    for (int j = 1; j < n; j++) {
      dpb[arr[i]][j] += dpb[arr[i]][j - 1];
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++)
    solve();
}