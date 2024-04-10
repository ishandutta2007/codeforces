#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

void finish(int x, int d) {
  printf("%d %d\n", x, d);
  exit(0);
}

int N, M;
int a[MAXN];
int b[MAXN];
bool bio[MAXN];

void load() {
  scanf("%d%d", &M, &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

inline int add(int x, int y) {
  x += y;
  if (x >= M)
    x -= M;
  else if (x < 0)
    x += M;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % M;
}

int pot(int x, int y) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

int inv(int x) {
  assert(x);
  return pot(x, M - 2);
}

void check(int x, int d) {
  for (int i = 0; i < N; i++)
    b[i] = add(x, mul(i, d));
  sort(b, b + N);
  for (int i = 0; i < N; i++)
    if (a[i] != b[i])
      return;
  finish(x, d);
}

void brute() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) 
      check(a[i], add(a[j], -a[i]));
  puts("-1");
}

void solve() {
  sort(a, a + N);
  
  if (N == M) 
    finish(0, 1);
    
  if (N < 100) {
    brute();
    return;
  }
  
  int sum = 0, sq = 0;
  for (int i = 0; i < N; i++) {
    sum = add(sum, a[i]);
    sq = add(sq, mul(a[i], a[i]));
  }
  
  int f = -1;
  if (N == M - 1) {
    for (int i = 0; i < N; i++)
      bio[a[i]] = true;
    for (int i = 0; i < M; i++)
      if (!bio[i])
        f = i;
  }

  int k = mul(2, inv(N - 1));
  int l = mul(sum, inv(N));
  int val = mul(mul(N, mul(N - 1, 2 * N - 1)), inv(6));
  for (int i = 0; i < N; i++) {
    int x = a[i];
    int d = mul(k, add(l, -x));
    if (f == -1) {
      int curr = add(mul(N, mul(x, x)), add(mul(x, mul(d, mul(N, N - 1))), mul(mul(d, d), val)));
      if (curr == sq) 
        check(x, d);
    }
    else if (add(x, mul(N, d)) == f)
      finish(x, d);  
  }
  
  puts("-1");
}

int main() {
  load();
  solve();
  return 0;
}