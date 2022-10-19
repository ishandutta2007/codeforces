#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+2;
int p[N];

int query(int i) {
  cout << "? " << i << endl;
  int ans;
  cin >> ans;
  if (!ans) exit(0);
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      p[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      if (!p[i]) {
        int start = query(i);
        vector<int> vals = {start};
        while (1) {
          int k = query(i);
          if (k == start) break;
          vals.push_back(k);
        }
        int m = vals.size();
        for (int j = 0; j < m-1; j++) {
          p[vals[j]] = vals[j+1];
        }
        p[vals.back()] = start;
      }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
      cout << p[i] << ' ';
    }
    cout << endl;
  }
}