/*


Q.E.D.
*/
/*
BULB: Instant 
result of thinking: Pure. 
 MO .

start coding:
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 500005
#define max2n 1000005
int n, p[max2n], lst[maxn], mate[max2n];
bool cho[max2n];

void odd() {
  puts("Second");
  fflush(stdout);
  for (int i = 1; i <= 2 * n; i++) {
    scanf("%d", p + i);
    if (!lst[p[i]])
      lst[p[i]] = i;
    else {
      mate[lst[p[i]]] = i;
      mate[i] = lst[p[i]];
    }
  }
  // lst[] is also used as vis[].
  for (int i = 1; i <= n; i++) {
    if (lst[i]) {
      int u = lst[i];
      do {
        lst[p[u]] = 0;
        cho[u] = true;
        u = (mate[u] + n - 1) % (2 * n) + 1;
      } while (lst[p[u]]);
    }
  }
  ll sum = 0;
  for (int i = 1; i <= 2 * n; i++) {
    sum += cho[i] * i;
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (cho[i] ^ (sum & 1)) {
      printf("%d ", i);
    }
  }
  puts("");
  fflush(stdout);
}

int main() {
  scanf("%d", &n);
  if (n & 1) {
    odd();
  } else {
    puts("First");
    for (int i = 0; i < 2 * n; i++) {
      printf("%d ", i % n + 1);
    }
    puts("");
    fflush(stdout);
  }
  int res;
  scanf("%d", &res);
  return 0;
}