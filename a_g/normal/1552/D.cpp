#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    bool valid = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) valid = 1;
    }
    set<int> subsetsums;
    subsetsums.insert(0);
    for (int j = 1; j < (1<<n); j++) {
      int sum = 0;
      for (int k = 0; k < n; k++) {
        if ((j>>k)&1) sum += a[k];
      }
      if (subsetsums.count(sum)) {
        valid = 1;
        break;
      }
      subsetsums.insert(sum);
    }
    cout << (valid ? "YES" : "NO") << endl;
  }
}