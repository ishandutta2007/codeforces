#include <math.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int solve(int n, int m);

int main () {
  int n, m;
  cin >> n >> m;
  cout << solve(n, m) << endl;
}

int solve(int n, int m) {
  long long a[4000001] = {0};
  a[1] = 1;
  a[2] = 2;
  int i = 2;
  /*while (i <= n) {
    long long ans = (2*a[i-1] + 1) % m;
    for (int d = 2; d < i; d++) {
      if (i % d == 0) {
        ans += a[i/d] - a[i/d-1];
        ans %= m;
      }
    }
    if (ans < 0) {ans += m;}
    a[i] = ans;
    i++;
  }*/
  while (i <= n) {
    if (a[i] < 0) {a[i] += m;}
    for (int j = 2; j <= n/i; j++) {
      a[i*j] += a[i]-a[i-1];
      a[i*j] %= m;
    }
    a[i+1] += 2*a[i]+1;
    a[i+1] %= m;
    i += 1;
  }
  return a[n];
}