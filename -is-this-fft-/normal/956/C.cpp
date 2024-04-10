#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

typedef long long ll;

int arr [MAX_N];
int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur = max(cur, arr[i] + 1);
    ans[i] = cur;
    cur = max(cur - 1, 0);
  }

  for (int i = 1; i < n; i++) {
    ans[i] = max(ans[i], ans[i - 1]);
  }

  ll sol = 0;
  for (int i = 0; i < n; i++) {
    sol += ans[i] - arr[i] - 1;
  }

  cout << sol << endl;
}