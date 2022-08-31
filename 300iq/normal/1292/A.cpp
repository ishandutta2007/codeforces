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
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <vector <int> > a(2, vector <int> (n));
  auto check = [&] (int i, int j) {
    if (i < 0 || j >= n) {
      return true;
    }
    for (int x = 0; x < 2; x++) {
      if (!a[x][i] && !a[x][j]) {
        return true;
      }
    }
    return false;
  };
  bool good = true;
  int s = 0;
  vector <int> ans(n);
  for (int i = 0; i < q; i++) {
    int r, c;
    cin >> r >> c;
    r--, c--;
    a[r][c] ^= 1;
    if (c - 1 >= 0) {
      s -= ans[c - 1];
      ans[c - 1] = !check(c -1, c);
      s += ans[c - 1];
    }
    if (c + 1 < n) {
      s -= ans[c];
      ans[c] = !check(c, c + 1);
      s += ans[c];
    }
    if (!s) cout << "Yes\n";
    else cout << "No\n";
  }
}