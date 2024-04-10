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

const int N = 3e5 + 67;
const int M = 998244353;

void add(int &a, int b) {
  a += b;
  if (a < 0) a += M;
  if (a >= M) a -= M;
}

int mul(int a, int b) {
  return (a * (ll) b) % M;
}

vector <int> g[N];
int dp[N][2][2];
int ok[2][2];
int nok[2][2];

void dfs(int v, int pr) {
  vector <int> ch;
  for (int to : g[v]) {
    if (to != pr) {
      dfs(to, v);
      ch.push_back(to);
    }
  }
  for (int need_me = 0; need_me < 2; need_me++) {
    for (int up_edge = 0; up_edge < 2; up_edge++) {
      if (pr == -1 && up_edge) continue;
      if (!need_me && up_edge) continue;
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          ok[i][j] = 0;
        }
      }
      ok[up_edge][0] = 1;
      for (int x : ch) {
        for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) nok[i][j] = 0;
        for (int grab_edge = 0; grab_edge < 2; grab_edge++) {
          if (!need_me && grab_edge) continue;
          for (int duba = 0; duba < 2; duba++) {
            for (int me = 0; me < 2; me++) {
              for (int zuba = 0; zuba < 2; zuba++) {
                add(nok[me | grab_edge][zuba | (duba & grab_edge)], mul(ok[me][zuba], dp[x][grab_edge][duba]));
              }
            }
          }
        }
        for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) ok[i][j] = nok[i][j];
      }
      add(dp[v][up_edge][0], ok[need_me][0]);
      add(dp[v][up_edge][0], ok[need_me][1]);
      if (need_me)
        add(dp[v][up_edge][1], ok[need_me][0]);
    }
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
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  int x = dp[0][0][0];
  add(x, dp[0][0][1]);
  add(x, M - 1);
  cout << x << endl;
}