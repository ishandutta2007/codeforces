#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    map<int, int> prv;
    vector<int> t;
    vector<pair<int, int>> ops;
    int start = 0;
    auto reverse_pref = [&] (int m, bool x) {
      for (int i = x; i < m; i++) {
        a.insert(a.begin()+start+m+i, a[start+i]);
        a.insert(a.begin()+start+m+i, a[start+i]);
        ops.emplace_back(start+m+i, a[start+i]);
      }
      t.push_back(2*m);
      start += 2*m;
    };
    auto output = [&] () {
      cout << ops.size() << '\n';
      for (pair<int, int>& p: ops) {
        cout << p.first << " " << p.second << '\n';
      }
      cout << t.size() << '\n';
      for (int z: t) {
        cout << z << ' ';
      }
      cout << '\n';
    };

    for (int i = 0; i < a.size(); ) {
      if (prv.count(a[i])) {
        int j = prv[a[i]];
        int m = j-start+1;
        int l = i-start;
        reverse_pref(m, 0);
        reverse_pref(l, 1);
        prv.clear();
        i = start;
      }
      else {
        prv[a[i]] = i;
        i++;
      }
    }
    if (!prv.empty()) {
      cout << "-1\n";
      continue;
    }

    output();
  }
}