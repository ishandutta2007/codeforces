#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int rcount[N];
int bcount[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    bool fail = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        if (a[i] > n) {
          fail = 1;
          break;
        }
        rcount[max(1, a[i])]++;
      }
      else {
        if (a[i] < 1) {
          fail = 1;
          break;
        }
        bcount[min(n, a[i])]++;
      }
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      tot += bcount[i];
      if (tot > i) {
        fail = 1;
        break;
      }
    }
    tot = 0;
    for (int i = n; i >= 1; i--) {
      tot += rcount[i];
      if (tot > n+1-i) {
        fail = 1;
        break;
      }
    }
    cout << (fail ? "NO" : "YES") << '\n';
    fill(rcount+1, rcount+n+1, 0);
    fill(bcount+1, bcount+n+1, 0);
  }
}