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


int main() {
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int st = 0; st < n; st++) {
      vector<int> b;
      for (int j = 0; j < n; j++) {
        if ((j >> st) == i) b.push_back(a[j]);
      }
      bool bad = false;
      for (int i = 1; i < (int) b.size(); i++) {
        if (b[i] < b[i - 1]) bad = true;
      }
      if (!bad) ans = max(ans, (int) b.size());
    }
  }
  cout << ans << endl;
}