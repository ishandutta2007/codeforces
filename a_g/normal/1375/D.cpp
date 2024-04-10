#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n;
int a[N];
bool found[N];

int mex() {
  for (int i = 0; i <= n; i++) found[i] = 0;
  for (int i = 0; i < n; i++) found[a[i]] = 1;
  for (int i = 0; i <= n; i++) {
    if (!found[i]) return i;
  }
  assert(0);
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ops;
    while (1) {
      int m = mex();
      if (m == n) {
        bool done = 1;
        for (int i = 0; i < n; i++) {
          if (a[i] != i) {
            a[i] = m;
            ops.push_back(i+1);
            done = 0;
            break;
          }
        }
        if (done) break;
      }
      else {
        a[m] = m;
        ops.push_back(m+1);
      }
    }
    cout << ops.size() << '\n';
    for (int k: ops) cout << k << ' ';
    cout << '\n';
  }
}