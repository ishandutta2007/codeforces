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

const int N = 3e5;

int dsu[N];

int get(int v) {
  if (v == dsu[v]) return v;
  else return dsu[v] = get(dsu[v]);
}

void uni(int u, int v) {
  dsu[get(u)] = get(v);
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < N; i++) dsu[i] = i;
  int n;
  cin >> n;
  vector <string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (auto &c : s[i])  {
      uni(c - 'a', 26 + i);
    }
  }
  set <int> q;
  for (int i = 0; i < n; i++) {
    q.insert(get(26 + i));
  }
  cout << q.size() << endl;
}