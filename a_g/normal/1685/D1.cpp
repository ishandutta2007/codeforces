#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> pinv(n);
    vector<int> cycid(n);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
      pinv[p[i]] = i;
    }
    int id = 0;
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      while (!vis[i]) {
        cycid[i] = id;
        vis[i] = 1;
        i = p[i];
      }
      id++;
    }
    for (int i = 0; i < n; i++) {
      if (cycid[i]) {
        assert(i > 0);
        p[pinv[i]] = i-1;
        p[pinv[i-1]] = i;
        swap(pinv[i-1], pinv[i]);
        int k = cycid[i];
        for (int j = 0; j < n; j++) {
          if (cycid[j] == k) cycid[j] = 0;
        }
      }
    }
    vector<int> q(1, 1);
    for (int i = 0; i < n-1; i++) {
      q.push_back(pinv[q.back()-1]+1);
    }
    for (int k: q) {
      cout << k << ' ';
    }
    cout << '\n';
  }
}