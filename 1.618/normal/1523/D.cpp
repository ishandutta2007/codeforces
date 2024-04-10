/*


Q.E.D.

result of thinking: Lost.

#

NPC.
CF1105E.

AC: 15:00
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
#define maxm 65

mt19937 rng;
int n, m, p;
ll ans;
char s[maxn][maxm];
int cnt[(1 << 15) + 5];

void work(int r) {
  vector<int> col;
  for (int i = 1; i <= m; i++)
    if (s[r][i] == '1')
      col.push_back(i);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) {
    int msk = 0;
    for (int j = 0; j < (int)col.size(); j++) {
      if (s[i][col[j]] == '1')
        msk |= 1 << j;
    }
    cnt[msk]++;
  }
  for (int i = 0; i < (int)col.size(); i++) {
    for (int S = 0; S < (1 << col.size()); S++) {
      if (!(S >> i & 1))
        cnt[S] += cnt[S | (1 << i)];
    }
  }
  int T = 0;
  for (int S = 0; S < (1 << col.size()); S++) {
    if (cnt[S] >= (n + 1) / 2 && __builtin_popcount(S) > __builtin_popcount(T))
      T = S;
  }
  ll res = 0;
  for (int i = 0; i < (int)col.size(); i++) {
    if (T >> i & 1)
      res |= 1ll << col[i];
  }
  if (__builtin_popcountll(res) > __builtin_popcountll(ans))
    ans = res;
}

int main() {
  rng.seed(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; i++)
    scanf("%s", s[i] + 1);
  for (int i = 1; i <= 50; i++)
    work(rng() % n + 1);
  for (int i = 1; i <= m; i++)
    printf("%d", ans >> i & 1);
  puts("");
  return 0;
}