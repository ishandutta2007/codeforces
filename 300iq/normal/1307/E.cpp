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

const int M = 1e9 + 7;


struct triple {
  int vl, vr, type;
};

const int N = 1e5;

int a[N], b[N], ct[N], rofl[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    s[i]--;
  }
  vector <triple> e;
  for (int i = 0; i < m; i++) {
    int f, h;
    cin >> f >> h;
    f--;
    int vl = -1, vr = -1;
    int have = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == f) {
        have++;
      }
      if (have == h) {
        vl = i;
        break;
      }
    }
    if (vl == -1) continue;
    have = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == f) {
        have++;
      }
      if (have == h) {
        vr = i;
        break;
      }
    }
    e.push_back({vl, vr, f});
  }
  vector <int> mda(n);
  for (auto c : e) {
    mda[c.type]++;
  }
  int ugar = 1;
  int gays = 0;
  for (int i = 0; i < n; i++) {
    if (mda[i]) {
      ugar = (ugar * (ll) mda[i]) % M;
      gays++;
    }
  }
  vector <pair <int, int> > ans;
  ans.push_back({gays, ugar});
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < n; i++) {
      a[i] = b[i] = ct[i] = rofl[i] =0 ;
    }
    for (auto c : e) {
      if (c.vl < x) {
        a[c.type]++;
      }
      if (c.vr > x) {
        b[c.type]++;
      }
      if (c.vl < x && c.vr > x) {
        a[c.type]--, b[c.type]--;
        ct[c.type]++;
      }
    }
    for (auto c : e) {
      if (c.vl == x) {
        if (c.vl < x) {
          a[c.type]--;
        }
        if (c.vr > x) {
          b[c.type]--;
        }
        if (c.vl < x && c.vr > x) {
          a[c.type]++, b[c.type]++;
          ct[c.type]--;
        }
        int grab = 1;
        int val = 1;
        for (int i = 0; i < n; i++) {
          if (i != c.type) {
            if (!a[i] && !b[i] && !ct[i]) continue;
            int mx = 0;
            int ways = 0;
            for (int grab_a = 0; grab_a < 3; grab_a++) {
              int rofl = 0;
              if (grab_a == 1) {
                rofl += a[i];
                a[i]--;
              } else if (grab_a == 2) {
                rofl += ct[i];
                ct[i]--;
              } else {
                rofl = 1;
              }
              int gays = bool(grab_a);
              if (a[i] >= 0 && ct[i] >= 0) {
                if (b[i] + ct[i]) {
                  gays++;
                  rofl = rofl * (b[i] + ct[i]);
                }
              }
              if (gays > mx) {
                mx = gays;
                ways = rofl;
              } else if (gays == mx) {
                ways += rofl;
                if (ways >= M) ways -= M;
              }
              if (grab_a == 1) {
                a[i]++;
              } else if (grab_a == 2) {
                ct[i]++;
              }
            }
            grab += mx;
            val = (val * (ll) ways) % M;
          } else {
            if (b[i] + ct[i]) {
              grab++;
              val = (val * (ll) (b[i] + ct[i])) % M;
            }
          }
        }
        ans.push_back({grab, val});
        if (c.vl < x) {
          a[c.type]++;
        }
        if (c.vr > x) {
          b[c.type]++;
        }
        if (c.vl < x && c.vr > x) {
          a[c.type]--, b[c.type]--;
          ct[c.type]++;
        }
      }
    }
  }
  int mx = 0;
  for (auto c : ans) {
    mx = max(mx, c.first);
  }
  int rofl = 0;
  for (auto c : ans) {
    if (c.first == mx) {
      rofl += c.second;
      if (rofl >= M) rofl -= M;
    }
  }
  cout << mx << ' ' << rofl << endl;
}