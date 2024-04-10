#include <bits/stdc++.h>
using namespace std;

const int N = 1505;
int freq[N];

bool query(int a, int b, int c) {
  cout << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << endl;
  string ans;
  cin >> ans;
  return ans == "Yes";
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n, k;
  cin >> n >> k;
  int m = 1;
  int dep = 0;
  while (m < n) {
    dep++;
    m = k*m+1;
  }
  while (1) {
    int u = rng()%n;
    int v = rng()%n;
    if (u == v) continue;
    vector<int> between;
    for (int w = 0; w < n; w++) {
      if (w == u || w == v) continue;
      if (query(u, w, v)) {
        between.push_back(w);
      }
    }
    if ((int)between.size() == 2*dep-1) {
      sort(between.begin(), between.end(), [&] (int x, int y) {
          return query(x, y, v);
          });
      cout << "! " << between[dep-1]+1 << endl;
      return 0;
    }
  }
}