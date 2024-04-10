#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }

    int best = -1;
    vector<int> p(m);
    for (int mask = 0; mask < (1<<n); mask++) {
      vector<pair<int, int>> solves(m);
      for (int j = 0; j < m; j++) {
        solves[j].second = j;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (s[i][j] == '1') {
            if ((mask>>i)&1) solves[j].first++;
            else solves[j].first--;
          }
        }
      }

      sort(solves.begin(), solves.end());
      vector<int> q(m);
      for (int j = 0; j < m; j++) {
        q[solves[j].second] = j+1;
      }

      /*
      cout << mask << endl;
      for (pair<int, int> x: solves) {
        cout << x.first << " " << x.second << endl;
      }
      for (int i: q) cout << i << ' ';
      cout << endl;
      */
      int d = 0;
      for (int i = 0; i < n; i++) {
        int score = 0;
        for (int j = 0; j < m; j++) {
          if (s[i][j] == '1') score += q[j];
        }
        d += abs(score-x[i]);
      }
      if (d > best) {
        best = d;
        p = q;
      }
    }

    //cout << best << endl;
    for (int i: p) cout << i << ' ';
    cout << '\n';
  }
}