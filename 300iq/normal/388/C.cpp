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
  ll l = 0, r = 0;
  vector <int> ord;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector <int> arr(k);
    for (int i = 0; i < k; i++) cin >> arr[i];
    for (int i = 0; i < k / 2; i++) r += arr[i];
    for (int i = (k + 1) / 2; i < k; i++) l += arr[i];
    if (k % 2) {
      ord.push_back(arr[k / 2]);
    }
  }
  sort(ord.rbegin(), ord.rend());
  for (int i = 0; i < (int) ord.size(); i++) {
    if (i % 2 == 1) l += ord[i];
    else r += ord[i];
  }
  cout << r << ' ' <<l  << '\n';
}