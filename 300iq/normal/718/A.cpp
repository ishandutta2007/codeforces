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
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  vector <int> moves(s.size());
  const int inf = 1e9 + 228;
  for (int i = (int) s.size() - 1; i >= 0; i--) {
    if (s[i] >= '5') {
      moves[i] = 1;
    } else if (s[i] < '4') {
      moves[i] = inf;
    } else {
      moves[i] = 1 + moves[i + 1];
    }
  }
  int p = -1;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '.') {
      p = i;
    }
  }
  for (int i = p+1; i < (int) s.size(); i++) {
    if (moves[i] <= t) {
      if (i - 1 != p) {
        s[i-1]++;
        cout << s.substr(0, i) << '\n';
        return 0;
      } else {
        s[i-2]++;
        int len = i - 1;
        for (int j = i - 2; j >= 0; j--) {
          if (s[j] > '9') {
            s[j] -= 10;
            if (j == 0) {
              len++;
              s.insert(s.begin(),'1');
            } else {
              s[j-1]++;
            }
          }
        }
        cout << s.substr(0,len) << '\n';
        return 0;
      }
    }
  }
  cout << s << endl;
}