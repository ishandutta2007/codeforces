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

const int N = 100;

bool win[N][N][2][2];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int a= 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          if (i == 0 && j == 0) {
            win[i][j][a][b] = (a == 1);
          } else {
            if (i) {
              win[i][j][a][b] |= !win[i - 1][j][b][a];
            }
            if (j) {
              win[i][j][a][b] |= !win[i][j - 1][b][a ^ 1];
            }
          }
        }
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int xr = 0;
    for (int i = 0; i < n; i++) {
      xr ^= a[i];
    }
    if (xr == 0) {
      cout << "DRAW\n";
    } else {
      for (int j = 30; j >= 0; j--) {
        if ((xr >> j) & 1) {
          for (int i = 0; i < n; i++) {
            a[i] = ((a[i] >> j) & 1);
          }
          break;
        }
      }
      int ones = 0;
      int zeroes = 0;
      for (int i = 0; i < n; i++) {
        if (a[i]) ones++;
        else zeroes++;
      }
      if (zeroes % 2 == 0 && ones % 4 == 3) {
        cout << "LOSE\n";
      } else {
        cout << "WIN\n";
      }
    }
  }
}