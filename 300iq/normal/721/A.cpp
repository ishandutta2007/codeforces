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

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector <int> ans;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      int len = 0;
      for (int j = i; j < n; j++) {
        if (s[j] != 'B') {
          break;
        } else {
          len++;
        }
      }
      i += len - 1;
      ans.push_back(len);
    }
  }
  cout << ans.size() << endl;
  for (int x : ans) cout << x << ' ';
  cout << endl;
}