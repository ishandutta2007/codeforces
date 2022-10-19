#include <bits/stdc++.h>
using namespace std;

const int N = 90;
long long fib[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fib[1] = 1;
  long long x = pow(10, 18);
  for (int i = 2; i < N; i++) {
    fib[i] = fib[i-1]+fib[i-2];
  }
  int n;
  long long l;
  cin >> n >> l;
  l--;
  vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  int len = n;
  while (len > 1) {
    if (l >= fib[len]) {
      swap(p[n-len], p[n-len+1]);
      l -= fib[len];
      len -= 2;
    }
    else {
      len -= 1;
    }
  }
  for (int x: p) {
    cout << x << ' ';
  }
  cout << '\n';
}