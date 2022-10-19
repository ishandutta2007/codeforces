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
    set<int> values;
    int a;
    int maximum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      values.insert(a);
      maximum = max(a, maximum);
    }
    int mex = 0;
    while (values.find(mex) != values.end()) {
      mex++;
    }
    while (k > 0 && mex < maximum) {
      while (values.find(mex) != values.end()) {
        mex++;
      }
      int newval = (mex+maximum+1)/2;
      values.insert(newval);
      if (newval != mex) {
        k = 0;
      }
      else {
        mex++;
      }
    }
    cout << values.size() + k << endl;

  }
}