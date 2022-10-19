#include <bits/stdc++.h>
using namespace std;

int query(string s) {
  cout << "? " << s << endl;
  int k;
  cin >> k;
  return k;
}

void answer(int L) {
  cout << "! " << L << endl;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> l(m);
  for (int i = 0; i < m; i++) {
    string s(m, '0');
    s[i] = '1';
    l[i] = query(s);
  }
  vector<int> indices(m);
  iota(indices.begin(), indices.end(), 0);
  sort(indices.begin(), indices.end(), [&] (int x, int y) {return l[x] < l[y];});
  int cur = 0;
  string mst(m, '0');
  for (int i: indices) {
    mst[i] = '1';
    int k = query(mst);
    if (k != cur+l[i]) {
      mst[i] = '0';
    }
    else {
      cur = k;
    }
  }
  answer(cur);
}