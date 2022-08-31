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
  int n;
  cin >> n;
  vector <int> a(n);
  vector <char> vis(1001);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector <int> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (vis[a[i]]) a[i] = -1;
    else vis[a[i]] = true;
    if (a[i] != -1) ans.push_back(a[i]);
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int x : ans) cout << x << ' ';
  cout << endl;
}