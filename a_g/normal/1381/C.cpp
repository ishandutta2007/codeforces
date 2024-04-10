#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> freq(n+2);
    vector<int> a(n), b(n);
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      c[i] = {++freq[a[i]], i};
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < x; i++) {
      b[c.back().second] = a[c.back().second];
      c.pop_back();
    }
    int k = n-x;
    vector<pair<int, int>> d(k);
    for (int i = 0; i < k; i++) {
      d[i] = {a[c[i].second], c[i].second};
    }
    sort(d.begin(), d.end());
    vector<pair<int, int>> d2 = d;
    rotate(d2.begin(), d2.begin()+k/2, d2.end());
    vector<int> bad_indices;
    for (int i = 0; i < k; i++) {
      if (d[i].first == d2[i].first) bad_indices.push_back(i);
    }

    if (bad_indices.size() > n-y) {
      cout << "NO\n";
      continue;
    }
    int z = -1;
    for (int i = 1; i <= n+1; i++) {
      if (!freq[i]) {
        z = i;
        break;
      }
    }

    for (int i = 0; i < k; i++) {
      if (d[i].first != d2[i].first && bad_indices.size() < n-y) bad_indices.push_back(i);
    }
    for (int i: bad_indices) {
      d2[i].first = z;
    }
    for (int i = 0; i < k; i++) {
      b[d[i].second] = d2[i].first;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      cout << b[i] << " \n"[i+1==n];
    }
  }
}