#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    set<int> vals;
    map<int, int> indices;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      vals.insert(val);
      indices[val] = i;
    }
    int mink = 0;
    int curr = 1e9;
    for (int val: vals) {
      if (curr+1 != indices[val]) {
        curr = indices[val];
        mink++;
      }
      else {
        curr++;
      }
    }
    cout << (k >= mink ? "Yes" : "No") << endl;
  }
}