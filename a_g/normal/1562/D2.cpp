#include <bits/stdc++.h>
using namespace std;

vector<int> c;
vector<int> partials;
unordered_map<int, vector<int>> revplus;
unordered_map<int, vector<int>> revminus;

int find (int l, int r) {
  int start = partials[l-1];
  int end = partials[r];
  // find a + to remove
  int target = (start+end+1)/2;
  auto x = upper_bound(revplus[target].begin(), revplus[target].end(), l-2);
  if (x != revplus[target].end() && *x < r) return *x+1;
  // find a - to remove
  target = (start+end-1)/2;
  return *upper_bound(revminus[target].begin(), revminus[target].end(), l-2)+1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    string rods;
    cin >> n >> q >> rods;
    c.resize(n);
    partials.resize(n+1);
    revplus.clear();
    revminus.clear();
    partials[0] = 0;
    for (int i = 0; i < n; i++) {
      c[i] = ((i&1)^(rods[i] == '+') ? 1 : -1);
      partials[i+1] = partials[i] + c[i];
      if (c[i] > 0) revplus[partials[i+1]].push_back(i);
      else revminus[partials[i+1]].push_back(i);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      int rods;
      if (!((r^l)&1)) {
        cout << 1 << '\n';
        cout << find(l, r) << '\n';
      }
      else {
        rods = partials[r] == partials[l-1] ? 0 : 2;
        cout << rods << '\n';
        if (rods) cout << l << " " << find(l+1, r) << '\n';
      }
    }
    //cout << endl;
  }
}