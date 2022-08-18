#include <stdlib.h>
#include <algorithm>
#include <assert.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

typedef long long llong;

llong K, statc;

int qc;
bool query (llong l, llong r) {
  qc++;
  assert(qc <= 4499);

  cout << l << " " << r << '\n';
  fflush(stdout);

  string ans;
  cin >> ans;
  if (l == r && ans[0] == 'Y') {
    exit(0);
  }

  if (ans[0] == 'B') {
    exit(0);
  }
  
  return ans[0] == 'Y';
}

llong randrange (llong l, llong r) {
  llong mod = r - l + 1;

  return l + rand() % mod;
}


llong extl (llong x) {
  return max(1LL, x - K);
}

llong extr (llong x) {
  return min(statc, x + K);
}

int main () {
  srand(time(NULL));
  ios::sync_with_stdio(false);
  
  cin >> statc >> K;
  
  llong l = 1, r = statc;
  while (true) {
    llong w = r - l + 1;
    if (w <= 7 * K) {
      llong guess = randrange(l, r);
      query(guess, guess);
    } else {
      llong mid = (l + r) / 2;
      if (query(l, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    l = extl(l);
    r = extr(r);
  }
}