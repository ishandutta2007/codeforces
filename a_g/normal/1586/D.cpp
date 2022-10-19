#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n;
  vector<int> ans(n);
  int maxfound = 0;
  for (int i = 2; i <= n; i++) {
    // find the last value
    cout << "? ";
    for (int j = 0; j < n-1; j++) {
      cout << "1 ";
    }
    cout << i << endl;
    cin >> k;
    if (k != 0) maxfound = i;
  }
  int last;
  if (maxfound == 0) last = n;
  else last = n+1-maxfound;
  ans[n-1] = last;
  for (int i = 1; i <= n; i++) {
    // find where i is
    if (i < last) {
      cout << "? ";
      for (int j = 0; j < n-1; j++) {
        cout << last+1 - i << " ";
      }
      cout << 1 << endl;
      cin >> k;
      ans[k-1] = i;
    }
    else if (i > last) {
      cout << "? ";
      for (int j = 0; j < n-1; j++) {
        cout << 1 << " ";
      }
      cout << i+1-last << endl;
      cin >> k;
      ans[k-1] = i;
    }
  }
  cout << "! ";
  for (int i: ans) {
    cout << i << " ";
  }
  cout << endl;
}