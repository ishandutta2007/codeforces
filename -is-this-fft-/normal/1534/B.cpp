#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  vector<ll> arr (n + 2, 0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  ll ops = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
      ll newh = max(arr[i - 1], arr[i + 1]);
      ops += arr[i] - newh;
      arr[i] = newh;
    }
  }

  ll ugly = 0;
  for (int i = 1; i <= n + 1; i++) {
    ugly += abs(arr[i] - arr[i - 1]);
  }

  cout << ops + ugly << '\n';
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