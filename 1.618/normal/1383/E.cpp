#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#define maxn 1000005

using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int n, k;
char s[maxn];
ll f[maxn], seg0[maxn], coe[maxn];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  ll lead0 = 0;
  while (s[lead0 + 1] == '0') lead0++;
  if (lead0 == n) {
    printf("%d\n", n);
    return 0;
  }
  ll tail0 = 0;
  while (s[n - tail0] == '0') tail0++;
  int l = lead0 + 1, r = n - tail0;
  for (int i = l; i < r; ) {
    int j = i + 1;
    while (s[j] == '0') j++;
    seg0[++k] = j - i - 1;
    i = j;
  }
  stack<int> stk;
  ll cur = 0;
  f[0] = 1;
  for (int i = 1; i <= k; i++) {
    while (!stk.empty() && seg0[stk.top()] <= seg0[i]) {
      (cur -= f[stk.top() - 1] * coe[stk.top()]) %= mod;
      stk.pop();
    }
    if (!stk.empty()) {
      (cur -= f[stk.top() - 1] * coe[stk.top()]) %= mod;
      coe[stk.top()] = seg0[stk.top()] - seg0[i];
      (cur += f[stk.top() - 1] * coe[stk.top()]) %= mod;
    }
    stk.push(i);
    coe[i] = seg0[i] + 1;
    (cur += f[i - 1] * coe[i]) %= mod;
    f[i] = (cur + 1) % mod;
  }
  printf("%lld\n", (f[k] * (lead0 + 1) % mod * (tail0 + 1) % mod + mod) % mod);
  return 0;
}