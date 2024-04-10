#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mex = 0;
    set<int> used;
    for (int i = 0; i < n; i++) {
      if (a[i] == mex) {
        mex++;
      }
    }
    for (int i = 0; i < mex; i++) {
      cout << i << " ";
    }
    for (int i = 0; i < n; i++) {
      int val = a[i];
      if (val < mex) {
        if (used.find(val) == used.end()) {
          used.insert(val);
        }
        else {
          cout << val << " ";
        }
      }
      else {
        cout << val << " ";
      }
    }
    cout << endl;
  }
}