#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 5e3 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, K;
  cin >> n >> K;

  map<int, int> minb;
  minb[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];

    int x = arr[i];
    for (int j = 1; j <= K; j++) {
      if (!minb.count(j * x)) {
        minb[j * x] = j;
      } else {
        minb[j * x] = min(minb[j * x], j);
      }
    }
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int x;
    cin >> x;

    int ans = K + 1;
    for (int j = 0; j < n; j++) {
      for (int k = 1; k <= K; k++) {
        int left = x - arr[j] * k;
        if (minb.count(left)) {
          ans = min(ans, minb[left] + k);
        }
      }
    }

    if (ans > K) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
}