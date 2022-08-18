#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_A = 1e5 + 5;

int ndiv (int a, int cdiv) {
  int p = a / cdiv;
  return a / p + 1;
}

vector<int> Q [MAX_A];

void solve () {
  int n, K;
  cin >> n >> K;

  vector<int> a (n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int cmin = INF;
  vector<int> cdiv (n, 1);
  for (int i = 0; i < n; i++) {
    Q[a[i] / cdiv[i]].push_back(i);
    cmin = min(cmin, a[i] / cdiv[i]);
  }

  int ans = INF;
  for (int val = MAX_A - 1; val >= 0; val--) {
    while (!Q[val].empty()) {
      ans = min(ans, val - cmin);
      int pos = Q[val].back();
      Q[val].pop_back();

      if (cdiv[pos] > a[pos]) {
        goto out;
      }

      cdiv[pos] = ndiv(a[pos], cdiv[pos]);
      if (cdiv[pos] > K) {
        goto out;
      }

      cmin = min(cmin, a[pos] / cdiv[pos]);
      Q[a[pos] / cdiv[pos]].push_back(pos);
    }
    Q[val].shrink_to_fit();
  }

 out:
  cout << ans << '\n';

  for (int i = 0; i < MAX_A; i++) {
    Q[i].clear();
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}