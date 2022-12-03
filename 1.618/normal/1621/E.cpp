/*
start thinking:
BULB:
result of thinking: Pure.

start coding:
AC:
*/
#include <bits/stdc++.h>
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
 
#define mp make_pair
#define maxn 100005
int n, m;
ldouble a[maxn];
pair<pair<ldouble, vector<int>>, int> b[maxn];
int bad0[maxn], bad1[maxn], bad2[maxn];
string s[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) 
    scanf("%Lf", a + i);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++)
    a[i] = a[i + n - m];
  for (int i = m + 1; i <= n + 1; i++)
    a[i] = 0;
  for (int i = 1; i <= m; i++) {
    s[i].clear();
    b[i].first.second.clear();
    int k;
    scanf("%d", &k);
    ldouble avr = 0;
    for (int j = 1; j <= k; j++) {
      int x;
      scanf("%d", &x);
      b[i].first.second.push_back(x);
      avr += x;
    }
    b[i].first.first = avr / k;
    b[i].second = i;
  }
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= m; i++) {
    bad0[i] = bad0[i - 1] + (b[i].first.first > a[i]);
  }
  for (int i = 2; i <= m; i++) {
    bad1[i] = bad1[i - 1] + (b[i].first.first > a[i - 1]);
  }
  for (int i = 1; i < m; i++) {
    bad2[i] = bad2[i - 1] + (b[i].first.first > a[i + 1]);
  }
  for (int i = 1; i <= m; i++) {
    int k = b[i].first.second.size();
    for (auto x : b[i].first.second) {
      ldouble avr = (b[i].first.first * k - x) / (k - 1);
      int rk = lower_bound(b + 1, b + m + 1, mp(mp(avr, (vector<int>){}), 0)) - b;
      if (rk > i + 1) {
        s[b[i].second] += (bad0[i - 1] == 0 && bad1[rk - 1] == bad1[i]
                            && avr <= a[rk - 1] && bad0[m] == bad0[rk - 1] 
                            ? "1" : "0");
      } else if (rk >= i) {
        s[b[i].second] += (bad0[i - 1] == 0 && avr <= a[i] && bad0[m] == bad0[i]
                            ? "1" : "0");
      } else {
        s[b[i].second] += (bad0[rk - 1] == 0 && avr <= a[rk] 
                            && bad2[i - 1] == bad2[rk - 1]
                            && bad0[m] == bad0[i] ? "1" : "0");
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%s", s[i].c_str());
  }
  puts("");
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}