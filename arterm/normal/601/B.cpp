#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#define long long long
const int M = 100100;

long mabs(long x) {
  return x < 0 ? -x : x;
}

int n, m;
long a[M], h[M];
long q[M], c[M], qf, qs, sum;

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  for (int i = 0; i + 1 < n; ++i) {
    a[i] = mabs(h[i + 1] - h[i]);
  }

}


void ini() {
  qf = qs = 0;
  sum = 0;
}

void pop() {
  --qf;
  sum -= q[qf] * c[qf];
}

void push(long x, long cnt) {
  assert(qs == qf || q[qf - 1] > x);
  sum += x * cnt;
  q[qf] = x;
  c[qf] = cnt;
  ++qf;
}

void add(long x) {
  long cur = 1;
  while (qs < qf && q[qf - 1] <= x) {
    pop();
    cur += c[qf];
  } 
  push(x, cur);
}

long get(long l, long r) {
  long ans = 0;
  ini();
  for (int i = l; i < r; ++i) {
    add(a[i]);
    ans += sum;
  } 
  return ans;
}


void kill() {
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    cout << get(l, r) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.precision(13);
  cout << fixed;
  read();
  kill();
  return 0;
}