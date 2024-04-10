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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

typedef long long ll;

int main() {
#ifdef ONPC
//  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
      vector <int> a, b;
      for (int j = 0; j < n; j++)
      {
        if ((j >> i) & 1) a.push_back(j);
        else b.push_back(j);
      }
      if (!a.empty() && !b.empty())
      {
        cout << a.size() << ' ' << b.size() << ' ';
        for (int v : a) cout << v + 1 << ' ';
        for (int v : b) cout << v + 1 << ' ';
        cout << endl;
        int ret;
        cin >> ret;
        ans = max(ans, ret);
      }
    }
    cout << -1 << ' ' << ans << endl;
  }
}