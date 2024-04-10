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

const int N = 2e5 + 7;

int t[4 * N];
int d[4 * N];

void build(int v, int l, int r, string &s) {
  d[v] = -1;
  if (r - l == 1) {
    t[v] = s[l] - '0';
  } else {
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m, s);
    build(v * 2 + 2, m, r, s);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
  }
}

void upd(int v, int x, int l, int r) {
  t[v] = x*  (r-l);
  d[v] = x;
}

void push(int v,int l, int r) {
  int m = (l + r) / 2;
  if (d[v] != -1) {
    upd(v*2+1,d[v],l,m);
    upd(v*2+2,d[v],m,r);
    d[v]=-1;
  }
}

int get(int v,int l,int r,int tl, int tr) {
  if (tl >= r || tr <= l) return 0;
  if (tl >= l && tr <= r) return t[v];
  else {
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    return get(v * 2 + 1, l, r, tl, tm) + get(v * 2 + 2, l, r, tm, tr);
  }
}

void upd(int v, int l, int r, int tl, int tr, int x) {
  if (tl >= r || tr <= l) return;
  if (tl >= l && tr <= r) {
    upd(v, x, tl, tr);
  } else {
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    upd(v * 2 + 1, l, r, tl, tm, x);
    upd(v * 2 + 2, l, r, tm, tr, x);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string f;
    cin >> f;
    build(0, 0, n, f);
    vector <int> l(q), r(q);
    for (int i = 0; i < q; i++) cin >> l[i] >> r[i];
    for (int i = 0; i < q; i++) l[i]--, r[i]--;
    bool bad = false;
    for (int i = q - 1; i >= 0; i--) {
      int b = get(0, l[i], r[i] + 1, 0, n);
      int a = (r[i] - l[i] + 1) - b;
      /*
      for (int j = l[i]; j <= r[i]; j++) {
        if (f[j] == '0') a++;
        else b++;
      }
      */
      if (a == b) {
        bad = true;
        break;
      } else if (a < b) {
        upd(0, l[i], r[i] + 1, 0, n, 1);
        //for (int j = l[i]; j <= r[i]; j++) f[j] = '1';
      } else {
        upd(0, l[i], r[i] + 1, 0, n, 0);
        //for (int j = l[i]; j <= r[i]; j++) f[j] = '0';
      }
    }
    for (int i = 0; i < n; i++) {
      if (get(0, i, i + 1, 0, n) != s[i] - '0') bad = true;
    }
    if (!bad) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}