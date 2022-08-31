#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  auto solve = [&] (vector <int> t) {
    int l = -1, r = (int) t.size() - 1;
    while (l < r - 1) {
      int m = (l + r) / 2;
      cout << "? " << m + 1 << ' ';
      for (int i= 0; i <= m; i++) cout << t[i] << ' ';
      cout << endl;
      int t;
      cin >> t;
      if (t == y || t == (x ^ y)) {
        r = m;
      } else {
        l = m;
      }
    }
    return t[r];
  };
  vector <char> ch(n + 1);
  int s = -1;
  for (int i = 0; (1 << i) <= n; i++) {
    vector <int> ans, bns;
    for (int j = 1; j <= n; j++) {
      if ((j >> i) & 1) {
        ans.push_back(j);
      } else {
        bns.push_back(j);
      }
    }
    cout << "? " << ans.size() << ' ';
    for (int x : ans) cout << x << ' ';
    cout << endl;
    int t;
    cin >> t;
    if (t == y || t == (x ^ y)) {
      ch[i] = true;
      if (ans.size() > bns.size()) {
        ans.swap(bns);
      }
      if (s == -1) {
        int a = solve(ans);
        s = a;
      }
    }
  }
  int z = s;
  for (int i = 0; i <= n; i++) {
    if (ch[i]) {
      z ^= (1 << i);
    }
  }
  if (s > z) swap(s, z);
  cout << "! " << s << ' ' << z << endl;
}