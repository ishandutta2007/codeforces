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

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector <map <int, int> > sum;
  map <int, int> dp;
  dp[0] = 1;
  const int mod = 1e9 + 7;
  for (int i = 0; i < 103; i++) {
    sum.push_back(dp);
    map <int, int> ndp;
    for (int x = 0; x < 26; x++) {
      for (auto c : dp) {
        int bal = c.first +x ;
        ndp[bal] += c.second;
        if (ndp[bal] >= mod) ndp[bal] -= mod;
      }
    }
    dp = ndp;
  }
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    int sm = 0;
    for (auto c : s)
      sm += c - 'a';
    int ret = sum[n][sm] - 1;
    if (ret < 0) ret += mod;
    cout << ret << '\n';
  }
}