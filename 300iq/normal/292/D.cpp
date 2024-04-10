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

const int N = 500;

int dsu[N];

int get(int v) {
  if (v == dsu[v]) return v;
  else return dsu[v] = get(dsu[v]);
}

void uni(int u, int v) {
  dsu[get(u)] = get(v);
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  for (int i = 0; i < n; i++) dsu[i] = i;
  vector <int> st;
  for (int i = 0; i < m; i++) {
    if (get(a[i]) != get(b[i])) {
      uni(a[i], b[i]);
      st.push_back(i);
    }
  }
  for (int i = 0; i < n; i++) dsu[i] = i;
  for (int i = m - 1; i >= 0; i--) {
    if (get(a[i]) != get(b[i])) {
      uni(a[i], b[i]);
      st.push_back(i);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    for (int i = 0; i < n; i++) dsu[i] = i;
    int s = n;
    for (int x : st) {
      if (x < l || x > r) {
        if (get(a[x]) != get(b[x])) s--;
        uni(a[x], b[x]);
      }
    }
    cout << s << '\n';
  }
}