#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_D = 1e6 + 5;
const int INF = 1e9 + 10;

int ceil (int p, int q) {
  return (p + q - 1) / q;
}

int xs [MAX_N];
bool invalid [MAX_N];

int a, b;
int _maxdiv [MAX_D];
int &maxdiv (int x) {
  return _maxdiv[x - a];
}

int _dp [MAX_D];
int &dp (int x) {
  return _dp[x - a];
}

int rmost [MAX_D]; // rightmost value where x is allowed to exist

void proc (int x) {
  if (x != a) {
    if (rmost[dp(x - 1)] >= x) {
      dp(x) = dp(x - 1);
    } else {
      dp(x) = dp(x - 1) + 1;
    }
  }

  rmost[dp(x) + 1] = max(rmost[dp(x) + 1], x + 1);
  if (maxdiv(x) != 0) {
    rmost[dp(x) + 1] = max(rmost[dp(x) + 1], x + xs[maxdiv(x)] - 1);
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  set<int> seen;
  for (int i = 1; i <= n; i++) {
    cin >> xs[i];
  }

  sort(xs + 1, xs + 1 + n);
  
  for (int i = 1; i <= n; i++) {
    if (seen.count(xs[i])) {
      invalid[i] = true;
    }
    seen.insert(xs[i]);
  }

  cin >> b >> a;

  for (int i = 1; i <= n; i++) {
    if (!invalid[i]) {
      for (int cur = xs[i] * ceil(a, xs[i]); cur <= b; cur += xs[i]) {
        maxdiv(cur) = i;
      }
    }
  }

  for (int i = a; i <= b; i++) {
    dp(i) = INF;
  }
  dp(a) = 0;

  for (int i = a; i <= b; i++) {
    proc(i);
  }

  cout << dp(b) << endl;
}