#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    bool rev = 0;
    vector<int> ops;
    int l = 0;
    int r = n-1;
    for (int i = n-1; i >= 0; i--) {
      if (!rev) {
        if (a[r] == b[i]) {
          r--;
          continue;
        }
        if (a[l] != b[i]) {
          ops.push_back(i+1);
        }
        else {
          ops.push_back(1);
          a[l] = b[i];
          ops.push_back(i+1);
        }
        l++;
        rev = 1;
      }
      else {
        if (a[r] == b[i]) {
          ops.push_back(i+1);
        }
        else {
          ops.push_back(1);
          a[r] = b[i];
          ops.push_back(i+1);
        }
        r--;
        rev = 0;
      }
    }

    cout << ops.size();
    for (int x: ops) cout << ' ' << x;
    cout << '\n';
  }
}