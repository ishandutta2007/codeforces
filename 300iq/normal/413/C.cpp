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
  int n, m;
  cin >> n >> m;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector <int> num(n);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    x--;
    num[x] = 1;
  }
  vector <int> ord(n);
  for (int i = 0; i < n; i++) ord[i] = i;
  sort(ord.begin(), ord.end(), [&] (int i, int j) {
    if (num[i] !=num[j]) return num[i]<num[j];
    else return a[i]>a[j];
  });
  ll ret = 0;
  for (int i= 0; i < n; i++) {
    if (!num[ord[i]]) {
      ret += a[ord[i]];
    } else {
      ret += max(ret, (ll) (a[ord[i]]));
    }
  }
  cout << ret << endl;

}