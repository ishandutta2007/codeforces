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

int a[3][2];
int na[3][2];
int d[7];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < 3; i++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < 7; i++) cin >> d[i];
    bool find_ans = false;
    vector <int> real_ret;
    for (int tot = 0; tot <= d[0]; tot++) {
      for (int x = 0; x <= d[1]; x++) {
        int kek = x;
        if (find_ans) continue;
        for (int i = 0; i < 3; i++) for (int j = 0; j < 2; j++) na[i][j] = a[i][j];
        bool bad = false;
        for (int i = 0; i < 3; i++) {
          na[i][0] -= tot;
          na[i][1] -= d[0] - tot;
          if (i != 2) {
            na[i][0] -= x;
            na[i][1] -= d[1] - x;
          }
          if (na[i][0] < 0 || na[i][1] < 0) bad = true;
        }
        if (bad) continue;
        int ta = d[2];//i!=1
        int tb = d[4];//i!=0
        int vl_ta = d[2] - na[0][1], vr_ta = na[0][0];
        int vl_tb = d[4] - na[1][1], vr_tb = na[1][0];
        vr_ta = min(vr_ta, d[2]);
        vr_tb = min(vr_tb, d[4]);
        vl_ta = max(0, vl_ta);
        vl_tb = max(0, vl_tb);
        if (vl_ta > vr_ta) continue;
        if (vl_tb > vr_tb) continue;
        int sum_l = d[2] + d[4] - na[2][1];
        int sum_r = na[2][0];
        sum_l = max(sum_l, 0);
        if (sum_l > sum_r) continue;
        if (max(vl_ta + vl_tb, sum_l) <= min(vr_ta + vr_tb, sum_r)) {
          int x = -1, y = -1;
          for (int i = vl_ta; i <= vr_ta; i++) {
            for (int j = vl_tb; j <= vr_tb; j++) {
              if (sum_l <= i + j && i + j <= sum_r) {
                x = i, y = j;
              }
            }
          }
          for (int i = 0; i < 3; i++) {
            if (i != 1) {
              na[i][0] -= x;
              na[i][1] -= d[2] - x;
            }
            if (i != 0) {
              na[i][0] -= y;
              na[i][1] -= d[4] - y;
            }
          }
          vector <int> ret(7);
          ret[0] = tot;
          ret[1] = kek;
          ret[2] = x;
          ret[4] = y;
          for (int p = 0; p < d[3]; p++) {
            if (na[0][0] > 0) {
              ret[3]++;
              na[0][0]--;
            } else {
              na[0][1]--;
            }
          }
          for (int p = 0; p < d[5]; p++) {
            if (na[1][0] > 0) {
              ret[5]++;
              na[1][0]--;
            } else {
              na[1][1]--;
            }
          }
          for (int p = 0; p < d[6]; p++) {
            if (na[2][0] > 0) {
              ret[6]++;
              na[2][0]--;
            } else {
              na[2][1]--;
            }
          }
          bool bd = false;
          for (int i = 0; i < 3; i++) for (int j = 0; j < 2; j++) if (na[i][j] < 0) bd = true;
          find_ans = true;
          if (!bd) real_ret = ret;
        }
      }
    }
    if (real_ret.empty()) cout << -1;
    else for (int x : real_ret) cout << x << ' ';
    cout << '\n';
  }
}