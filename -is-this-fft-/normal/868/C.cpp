#include <iostream>
#include <vector>

using namespace std;

bool has [16];

int main () {
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < K; j++) {
      int x;
      cin >> x;
      
      cur *= 2;
      cur += x;
    }

    has[cur] = true;
  }

  for (int mask = 1; mask < 1 << (1 << K); mask++) {
    bool ok = true;
    
    vector<int> sum (K);
    for (int i = 0; i < 1 << K; i++) {
      if (mask & 1 << i) {
        if (!has[i]) {
          ok = false;
        }
      
        for (int j = 0; j < K; j++) {
          if (i & 1 << j) {
            sum[j]--;
          } else {
            sum[j]++;
          }
        }
      }
    }

    for (int j = 0; j < K; j++) {
      if (sum[j] < 0) {
        ok = false;
      }
    }

    if (ok) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}