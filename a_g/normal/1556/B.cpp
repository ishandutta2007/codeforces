#include <bits/stdc++.h>
using namespace std;


int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      arr[i] = (a & 1);
      count += (a & 1);
    }
    if (count < n/2 || count > (n+1)/2) {
      cout << -1 << endl;
    }
    else {
      int zero_val = 0;
      int one_val = 0;
      int zero_pos = 0;
      int one_pos = 0;

      for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
          zero_val += abs(i-zero_pos);
          zero_pos += 2;
        }
        else {
          one_val += abs(i-one_pos);
          one_pos += 2;
        }
      }

      if (n & 1) {
        if (count == n/2) {
          cout << zero_val << endl;
        }
        else {
          cout << one_val << endl;
        }
      }
      else {
        cout << min(zero_val, one_val) << endl;
      }
    }
  }
}