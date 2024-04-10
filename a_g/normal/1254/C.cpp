#include <bits/stdc++.h>
using namespace std;

long long ar[1005];
long long max_ar[2];
int max_vtx[2];

long long query(int t, int i, int j, int k) {
  cout << t << " " << i << " " << j << " " << k << endl;
  long long ans;
  cin >> ans;
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> sides[2];
  // sides[0] = the part below A_1A_2
  for (int v = 3; v <= n; v++) {
    int k = query(2, v, 1, 2);
    ar[v] = query(1, v, 1, 2);

    if (k == -1) k = 0;
    if (!sides[k].size()) {
      sides[k].push_back(v);
      max_ar[k] = ar[v];
      max_vtx[k] = v;
      continue;
    }

    int l = query(2, max_vtx[k], v, 2-k);
    auto it = find(sides[k].begin(), sides[k].end(), max_vtx[k]);
    if (l == 1) {
      if (ar[v] >= max_ar[k]) {
        sides[k].insert(it+1, v);
      }
      else {
        bool done = 0;
        for (; it != sides[k].end(); it++) {
          if (ar[v] >= ar[*it]) {
            sides[k].insert(it, v);
            done = 1;
            break;
          }
        }
        if (!done) {
          sides[k].push_back(v);
        }
      }
    }
    else {
      assert(l == -1);
      if (ar[v] >= max_ar[k]) {
        sides[k].insert(it, v);
      }
      else {
        bool done = 0;
        for (; ; it--) {
          if (ar[v] >= ar[*it]) {
            sides[k].insert(it+1, v);
            done = 1;
            break;
          }
          if (it == sides[k].begin()) break;
        }
        if (!done) {
          sides[k].insert(sides[k].begin(), v);
        }
      }
    }

    if (ar[v] > max_ar[k]) {
      max_ar[k] = ar[v];
      max_vtx[k] = v;
    }
  }

  cout << "0 1";
  for (int x: sides[0]) {
    cout << " " << x;
  }
  cout << " 2";
  for (int x: sides[1]) {
    cout << " " << x;
  }
  cout << endl;
}