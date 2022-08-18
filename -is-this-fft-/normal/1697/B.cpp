#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 5;

ll arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, qc;
  cin >> n >> qc;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  sort(arr + 1, arr + n + 1);

  for (int i = 1; i <= n; i++) {
    arr[i] += arr[i - 1];
  }

  for (int i = 0; i < qc; i++) {
    int x, y;
    cin >> x >> y;

    int l = n - x + 1;
    int r = l + y - 1;
    cout << arr[r] - arr[l - 1] << '\n';
  }
}