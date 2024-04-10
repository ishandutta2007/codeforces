#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> arr (n);
  vector<int> zs;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0) {
      zs.push_back(i);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      if (!zs.empty() && (int) zs.back() > i) {
        int z = zs.back();
        zs.pop_back();
        arr[i] = 0;
        arr[z] = 1;
        ans++;
      }
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