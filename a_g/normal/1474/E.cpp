#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
int p[N];
vector<pair<int, int>> ops;
ll t;

void operate(int i, int j) {
  ops.push_back({i, j});
  t += 1LL * (j-i) * (j-i);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;

    t = 0;
    vector<int> c;
    c.push_back(1);
    for (int i = n/2+1; i < n; i++) c.push_back(i);
    c.push_back(n);
    for (int i = 2; i <= n/2; i++) c.push_back(i);
    for (int i = 0; i < n; i++) {
      p[c[i]-1] = c[(i+1)%n];
    }
    for (int i = n/2+1; i < n; i++) operate(i, 1);
    for (int i = 2; i <= n/2; i++) operate(i, n);
    operate(1, n);

    cout << t << '\n';
    for (int i = 0; i < n; i++) cout << p[i] << ' ';
    cout << '\n';
    cout << ops.size() << '\n';
    for (pair<int, int> op: ops) {
      cout << op.first << " " << op.second << '\n';
    }

    ops.clear();
  }
}