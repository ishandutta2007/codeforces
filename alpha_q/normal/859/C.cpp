#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 55;

int n, a[N];
pii f[N][2];
bool vis[N][2];

pii add (pii x, pii y) {
  return pii(x.first + y.first, x.second + y.second);
}

pii call (int at, int who) {
  if (at > n) return pii(0, 0);
  if (vis[at][who]) return f[at][who];
  vis[at][who] = 1;
  if (who == 0) {
    pii one = call(at + 1, 0); one.first += a[at];
    pii two = call(at + 1, 1); two.second += a[at];
    f[at][who] = (one.second > two.second ? one : two);
  } else {
    pii one = call(at + 1, 1); one.second += a[at];
    pii two = call(at + 1, 0); two.first += a[at];
    f[at][who] = (one.first > two.first ? one : two);
  }
  return f[at][who];
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  pii ans = call(1, 0);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}