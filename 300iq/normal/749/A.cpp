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
  if (n % 2 == 0) {
    cout << n / 2 << '\n';
    for (int i = 0; i < n / 2; i++) cout << 2 << ' ';
  } else {
    cout << (n - 3) / 2 + 1 << '\n';
    cout << 3 << ' ';
    for (int i = 0; i < (n - 3) / 2; i ++) cout << 2 << ' ';
  }
}