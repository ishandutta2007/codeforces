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

bool f[20][20];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool bad = false;
    for (int i = 0; i < 20; i++) for (int j = 0; j < 20; j++) f[i][j] = false;
    vector <char> need(20), ok(20);
    for (int i = 0; i < n; i++) {
      int x = a[i] - 'a', y = b[i] - 'a';
      if (x > y) {
        bad = true;
      } else {
        f[x][y] = true;
      }
    }
    if (bad) {
      cout << -1 << '\n';
      continue;
    }
    vector <char> used(20);
    int ans = 0;
    for (int i = 0; i < 20; i++) {
      if (!used[i]) {
        used[i] = true;
        vector <int> q;
        q.push_back(i);
        for (int j = 0; j < (int) q.size(); j++) {
          int v = q[j];
          for (int z= 0; z < 20; z++) if ((f[v][z] || f[z][v]) && !used[z]) {
            q.push_back(z);
            used[z] = true;
          }
        }
        ans += max(0, (int) q.size() - 1);
      }
    }
    cout << ans << '\n';
  }
}