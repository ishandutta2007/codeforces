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
    vector<int> lefts;
    vector<int> partners(2*n, -1);
    while (k--) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      partners[x] = y;
      partners[y] = x;
      lefts.push_back(x);
    }
    vector<int> unused;
    for (int i = 0; i < 2*n; i++) {
      if (partners[i] == -1) {
        unused.push_back(i);
      }
    }
    int m = unused.size()/2;
    for (int i = 0; i < m; i++) {
      partners[unused[i]] = unused[i+m];
      partners[unused[i+m]] = unused[i];
      lefts.push_back(unused[i]);
    }
    int intersections = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int a = lefts[i];
        int b = partners[a];
        int c = lefts[j];
        int d = partners[c];
        if (!(max(a, b) < min(c, d)
            || max(c, d) < min(a, b)
            || (max(a, b) < max(c, d) && min(a, b) > min(c, d))
            || (max(a, b) > max(c, d) && min(a, b) < min(c, d))
            )) {
          intersections++;
        }
      }
    }
    cout << intersections << endl;
  }
}