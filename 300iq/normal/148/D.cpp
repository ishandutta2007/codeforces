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

const int N = 1001;

double dp[N][N][2];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int w, b;
  cin >> w >> b;
  dp[0][0][1] = 1;
  dp[0][0][0] = 0;
  for (int i = 0; i <= w; i++) {
    for (int j = 0; j <= b; j++) {
      for (int t = 0; t < 2; t++) {
        if (!i && !j) continue;
        if (i) {
          dp[i][j][t] += i / (double) (i + j);
        }
        if (j) {
          double prob = j / (double) (i + j);
          int ni = i, nj = j - 1;
          if (t) {
          if (ni) {
            dp[i][j][t] += prob * (1 - dp[ni - 1][nj][t ^ 1]) * ni / (double) (ni + nj);
          }
          if (nj) {
            dp[i][j][t] += prob * (1 - dp[ni][nj - 1][t ^ 1]) * nj / (double) (ni + nj);
          }
          }
          if ((!ni && !nj) || !t) {
            dp[i][j][t] += prob * (1 - dp[ni][nj][t ^ 1]);
          }
        }
      }
    }
  }
  cout.precision(20);
  cout << dp[w][b][0] << endl;
}