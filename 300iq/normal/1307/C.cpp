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

ll ret[26][26];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  vector <int> cnt(26);
  for (int i = 0; i < (int) s.size(); i++) {
    cnt[s[i] - 'a']++;
  }
  ll ans = *max_element(cnt.begin(), cnt.end());
  vector <int> mda(26);
  for (int i = 0; i < (int) s.size(); i++) {
    int c = s[i] - 'a';
    for (int j = 0; j < 26; j++) {
      ret[j][c] += mda[j];
    }
    mda[c]++;
  }
  for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) ans = max(ans, ret[i][j]);
  cout << ans << endl;
}