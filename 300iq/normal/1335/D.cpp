#include <cmath>
#include <functional>
#include <fstream>
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
  int t;
  cin >> t;
  while (t--) {
    vector <string> s(9);
    for (int i = 0; i < 9; i++) cin >> s[i];
    vector <int> cs = {0, 3, 6, 1, 4, 7, 2, 5, 8};
    auto t = s;
    for (int r = 0; r < 9; r++) {
      int c = cs[r];
      int i = r, j = c;
      if (i % 3 == 2) i--;
      else i++;
      if (j % 3 == 2) j--;
      else j++;
      t[r][c] = s[i][j];
    }
    for (int i = 0; i < 9; i++) cout << t[i] << '\n';
  }
}