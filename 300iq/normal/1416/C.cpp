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

int sz = 1;

const int N = 30 * 3e5 + 10;

int go[N][2];
int cnt[N];
ll l[31], r[31];

void add(int x) {
  int v = 0;
  for (int i = 30; i >= 0; i--) {
    int c = ((x >> i) & 1);
    if (!go[v][c]) {
      go[v][c] = sz++;
    }
    if (c == 1) {
      l[i] += cnt[go[v][0]];
    } else {
      r[i] += cnt[go[v][1]];
    }
    v = go[v][c];
    cnt[v]++;
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    add(a[i]);
  }
  ll sum = 0;
  int ret = 0;
  for (int i = 0; i <= 30; i++) {
    if (l[i] < r[i]) ret += (1 << i);
    sum += min(l[i], r[i]);
  }
  cout << sum << ' ' << ret << '\n';
}