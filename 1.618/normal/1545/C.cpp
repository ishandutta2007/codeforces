/*


Q.E.D.

result of thinking: Lost.

.

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
const int inf = 0x3f3f3f3f;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

const int mod = 998244353;

#define maxn 505
int n, a[maxn << 1][maxn], row[maxn];
bool del[maxn << 1];

bool adj(int x, int y) { // a[x] & a[y] have somewhere same?
  for (int i = 1; i <= n; i++) 
    if (a[x][i] == a[y][i])
      return true;
  return false;
}

int nxt(int& cnt) {
  for (int i = 1; i <= n; i++) {
    memset(row, 0, sizeof(row));
    for (int j = 1; j <= n * 2; j++) {
      if (del[j])
        continue;
      if (!row[a[j][i]])
        row[a[j][i]] = j;
      else if (row[a[j][i]] > 0)
        row[a[j][i]] = -1;
    }
    for (int j = 1; j <= n; j++) {
      if (row[j] > 0) {
        for (int k = 1; k <= 2 * n; k++) {
          if (!del[k] && adj(row[j], k))
            del[k] = true;
        }
        return row[j];
      }
    }
  }
  (cnt <<= 1) %= mod;
  for (int i = 1; i <= 2 * n; i++) {
    if (del[i])
      continue;
    for (int j = 1; j <= 2 * n; j++) {
      if (!del[j] && adj(i, j))
        del[j] = true;
    }
    return i;
  }
}

void solve() {
  memset(del, 0, sizeof(del));
  scanf("%d", &n);
  for (int i = 1; i <= n * 2; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int cnt = 1;
  vector<int> ans;
  for (int i = 1; i <= n; i++)
    ans.push_back(nxt(cnt));
  printf("%d\n", (cnt + mod) % mod);
  for (auto i : ans)
    printf("%d ", i);
  puts("");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "did not RE" << endl;
  return 0;
}