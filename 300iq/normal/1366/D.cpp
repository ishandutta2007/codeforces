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

const int N = 1e7 + 10;

int lp[N];
int a[N], b[N];
bool in[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> ret;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    in[x] = true;
    ret.push_back(x);
  }
  auto relax = [&] (int x, int y) {
    if (lp[x] == 0) lp[x] = y;
    if (!a[x] && lp[x] && y % lp[x] && gcd(lp[x] + y, x) == 1) {
      a[x] = lp[x];
      b[x] = y;
    }
  };
  for (int i= 2; i < N; i++) {
    for (int j = i; j < N; j += i) {
      if (in[j])
        relax(j, i);
    }
  }
  for (int i = 0; i < n; i++) if (a[ret[i]]) cout << a[ret[i]] << ' '; else cout << -1 << ' ';
  cout << '\n';
  for (int i = 0; i < n; i++) if (b[ret[i]]) cout << b[ret[i]] << ' '; else cout << -1 << ' ';
  cout << '\n';
}