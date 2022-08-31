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

#ifdef ONPC
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int M = 1e9 + 7;

inline int add(int a, int b)
{
  a += b;
  if (a < 0) a += M;
  if (a >= M) a -= M;
  return a;
}

inline int mul(int a, int b)
{
  return (a * (ll) b) % M;
}

inline int pw(int a, int n)
{
  int res = 1;
  while (n)
  {
    if (n % 2 == 0)
    {
      a = mul(a, a);
      n /= 2;
    }
    else
    {
      res = mul(res, a);
      n--;
    }
  }
  return res;
}

inline int inv(int x)
{
  return pw(x, M - 2);
}

const int N = 1e6 + 7;

int fact[N];
int rfact[N];

int C(int n, int k)
{
  if (n < k) return 0;
  return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  fact[0] = 1;
  for (int i = 1; i < N; i++)
  {
    fact[i] = mul(fact[i - 1], i);
  }
  rfact[N - 1] = inv(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--)
  {
    rfact[i] = mul(rfact[i + 1], i + 1);
  }
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  int ans = 0;
  for (int x = 1; x <= n - 1 && x <= m; x++)
  {
    int kek = mul(C(m - 1, x - 1), mul(C(n - 2, x - 1), fact[x - 1]));
    kek = mul(kek, mul(x + 1, pw(n, (n - x - 2 + M - 1) % (M - 1))));
    kek = mul(kek, pw(m, n - (x + 1)));
    ans = add(ans, kek);
  }
  cout << ans << '\n';
}