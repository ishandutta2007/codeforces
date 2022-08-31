#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll arr [MAX_N];
ll L [MAX_N], R [MAX_N], C [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < n; i++) {
    if (arr[i] < 2) {
      L[i] = 0;
    } else {
      L[i] = L[i - 1];
      L[i] += arr[i] - arr[i] % 2;
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    if (arr[i + 1] < 2) {
      R[i] = 0;
    } else {
      R[i] = R[i + 1];
      R[i] += arr[i + 1] - arr[i + 1] % 2;
    }
  }

  for (int i = 1; i < n; i++) {
    C[i] = arr[i] + C[i - 1];
    if (arr[i] % 2 == 0) {
      C[i]--;
    }
  }

  ll ans = 0, mxa = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, R[i] + C[i] + mxa);
    mxa = max(mxa, L[i] - C[i]);
  }

  cout << ans << endl;
}