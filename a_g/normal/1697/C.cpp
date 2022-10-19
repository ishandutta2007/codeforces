#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string z, zt;
    vector<int> is, it;
    for (char c: s) {
      if (c != 'b') {
        z.push_back(c);
      }
      else {
        is.push_back(z.size());
      }
    }
    for (char c: t) {
      if (c != 'b') {
        zt.push_back(c);
      }
      else {
        it.push_back(zt.size());
      }
    }
    
    if (z != zt) {
      cout << "NO\n";
      continue;
    }

    int k = z.size();
    vector<int> p(k+1);
    for (int i = 0; i < k; i++) {
      p[i+1] = p[i] + (z[i] == 'a');
    }
    bool good = 1;
    for (int i = 0; i < (int)is.size(); i++) {
      if (is[i] > it[i]) {
        if (p[is[i]] - p[it[i]] != is[i]-it[i]) good = 0;
      }
      if (is[i] < it[i]) {
        if (p[it[i]] != p[is[i]]) good = 0;
      }
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}