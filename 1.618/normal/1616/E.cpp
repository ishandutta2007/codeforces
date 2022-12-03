/*
start thinking:
BULB:
result of thinking:

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

#define maxn 100005
int n, bit[maxn];
char s[maxn], t[maxn];
queue<int> pos[35];

void add(int pos, int x) {
  for (int i = pos; i <= n; i += i & -i) {
    bit[i] += x;
  }
}

int qsum(int pos) {
  int res = 0;
  for (int i = pos; i; i -= i & -i) {
    res += bit[i];
  }
  return res;
}

void solve() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  for (int i = 0; i < 26; i++) {
    while (pos[i].size())
      pos[i].pop();
  }
  for (int i = 1; i <= n; i++) {
    pos[s[i] - 'a'].push(i);
  }
  memset(bit, 0, sizeof(bit));
  for (int i = 1; i <= n; i++)
    add(i, 1);
  ll ans = infll, cur = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < t[i] - 'a'; j++) {
      if (pos[j].size()) {
        chmin(ans, qsum(pos[j].front()) - 1 + cur);

        // cout << ans << endl;
        // system("pause");

      }
    }
    if (pos[t[i] - 'a'].size()) {
      cur += qsum(pos[t[i] - 'a'].front()) - 1;
      add(pos[t[i] - 'a'].front(), -1);
      pos[t[i] - 'a'].pop();
    } else {
      break;
    }
  }
  printf("%lld\n", ans == infll ? -1 : ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
/*
1
3
rll
rrr
*/