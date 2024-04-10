#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> tries;
    for (int i = 0; i < n; i++) {
      if (a[i] != a[n-1-i]) {
        tries.insert(a[i]);
        tries.insert(a[n-1-i]);
        break;
      }
    }
    if (!tries.size()) {
      cout << "YES\n";
    }
    else {
      bool win = 0;
      for (int k: tries) {
        bool valid = 1;
        vector<int> b;
        //cout << k << endl;
        for (int j: a) {
          if (j != k){
            b.push_back(j);
            //cout << j << " ";
          }
        }
        //cout << endl;
        for (int i = 0; i < b.size(); i++) {
          if (b[i] != b[b.size()-1-i]) {
            valid = 0;
          }
        }
        if (valid) win = 1;
      }
      cout << (win ? "YES\n" : "NO\n");
    }
  }
}