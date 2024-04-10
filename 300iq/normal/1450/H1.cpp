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

int f(string s) {
  string str = "";
  int bal = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    int x = (s[i] == 'w');
    if (i % 2 == x) {
      bal++;
    } else {
      bal--;
    }
  }
  return abs(bal) / 4;
}

const int M = 998244353;

int mul(int a, int b) {
  return (a * (ll) b) % M;
}

void add(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
}

int pw(int a, int n) {
  int res = 1;
  while (n) {
    if (n % 2 == 0) {
      a = mul(a, a);
      n /= 2;
    } else {
      res = mul(res, a);
      n--;
    }
  }
  return res;
}

int inv(int x) {
  return pw(x, M - 2);
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1) {
      if (s[i] == 'b') s[i] = 'w';
      else if (s[i] == 'w') s[i] = 'b';
    }
    if (s[i] == '?') {
      x++;
    }
  }
  vector <int> fact(n + 1);
  fact[0] = 1;
  for (int i= 1; i <= n; i++) fact[i] = mul(fact[i - 1], i);
  vector <int> rfact(n + 1);
  for (int i = 0; i <= n; i++) rfact[i] = inv(fact[i]);
  int bal = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'w') bal++;
    else if (s[i] == 'b') bal--;
  }
  auto C = [&] (int n, int k) {
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
  };
  int sum = 0;
  int tot = 0;
  for (int ws = 0; ws <= x; ws++) {
    int val = C(x, ws);
    int ret = bal - ws + (x - ws);
    if (ret % 4 == 0) {
      add(sum, mul(abs(ret) / 4, val));
      add(tot, val);
    }
  }
  cout << mul(sum, inv(tot)) << '\n';
}