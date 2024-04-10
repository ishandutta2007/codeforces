/*
start thinking:
BULB:
result of thinking:

<> #Greedy

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005
int n, len[maxn];
ll a, b, c, num[2], lim[2];
vector<int> seg0;
char s[maxn];

void solve(int caseId) {
  scanf("%d%lld%lld%lld", &n, &a, &b, &c);
  scanf("%s", s + 1);
  num[0] = num[1] = lim[0] = lim[1] = 0;
  seg0.clear();
  for (int i = 1; i <= n; i++) {
    num[s[i] - '0']++;
    if (s[i] == s[i - 1])
      len[i] = len[i - 1] + 1;
    else
      len[i] = 1;
    if (s[i] != s[i + 1]) {
      lim[s[i] - '0']--;
      if (s[i] == '0' && i < n && len[i] != i)
        seg0.push_back(len[i]);
    }
  }
  if (n == 1) {
    puts("0");
    return;
  }
  if (len[n] == n && s[n] == '0') {
    printf("%lld\n", a);
    return;
  }
  lim[0] += num[0], lim[1] += num[1];
  sort(seg0.begin(), seg0.end());
  if (lim[1] >= lim[0]) {
    ll ans = lim[0] * (a + b);
    if (lim[1] > lim[0])
      ans += b;
    if (b > c) {
      ans += seg0.size() * (b - c);
      if (lim[1] > lim[0])
        ans += (b - c) * min(lim[1] - lim[0] - 1, num[0] - lim[0] - (ll)seg0.size());
    }
    printf("%lld\n", ans);
    return;
  }
  ll ans = lim[1] * (a + b) + a;
  if (b <= c) {
    printf("%lld\n", ans);
    return;
  }
  for (auto i : seg0) {
    if (lim[1] < i - 1) {
      printf("%lld\n", ans);
      return;
    }
    ans += b - c;
    lim[1] -= i - 1;
  }
  printf("%lld\n", ans);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++)
    solve(i);
  return 0;
}