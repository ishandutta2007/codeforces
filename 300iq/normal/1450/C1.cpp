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

vector <pair <int, int> > gg[3];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 3; i++) gg[i].clear();
    int n;
    cin >> n;
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      a[i] = s;
      for (int j = 0; j < n; j++) {
        if (s[j] == 'X') {
          gg[(i + j) % 3].push_back({i, j});
        }
      }
    }
    int x = 0;
    for (int i = 0; i < 3; i++) {
      if (gg[i].size() < gg[x].size()) x=  i;
    }
    for (auto c : gg[x]) {
      a[c.first][c.second] = 'O';
    }
    for (int i = 0; i < n; i++) cout << a[i] << '\n';
  }
}