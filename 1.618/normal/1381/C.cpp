#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define mp make_pair
#define maxn 100005
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n, x, y, f, mode, a[maxn], b[maxn]; // val, id.
int cnt[maxn];
vector<int> fir;
void make(int x) { // x = x, y = n.
  for (int i = 1; i <= n; i++) a[i] = b[i];
  if ((n - x) & 1) {
    for (int i = 0; i < (int)fir.size(); i++) {
      if (b[fir[i]] == mode) {
        swap(fir[i], fir[0]);
        break;
      }
    }
    swap(a[fir[0]], a[fir[1]]);
    swap(a[fir[0]], a[fir[2]]);
    vector<P> lis;
    int tmp = min(n - f - 2, f - 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] != b[i]) continue;
      if (a[i] == mode) {
        if (tmp) {
          tmp--;
          lis.push_back(mp(a[i], i));
        }
      } else {
        lis.push_back(mp(a[i], i));
      }
    }
    sort(lis.begin(), lis.end());
    int shift = lis.size() / 2;
    for (int i = 0; i < (n - 3 - x) / 2; i++)
      swap(a[lis[i].second], a[lis[i + shift].second]);
  } else {
    vector<P> lis;
    int tmp = min(n - f, f);
    for (int i = 1; i <= n; i++) {
      if (a[i] == mode) {
        if (tmp) {
          tmp--;
          lis.push_back(mp(a[i], i));
        }
      } else {
        lis.push_back(mp(a[i], i));
      }
    }
    sort(lis.begin(), lis.end());
    int shift = lis.size() / 2;
    for (int i = 0; i < (n - x) / 2; i++)
      swap(a[lis[i].second], a[lis[i + shift].second]);
  }
}
void solve() {
  fir.clear();
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n + 1; i++) cnt[i] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    if (!cnt[b[i]]) fir.push_back(i); 
    cnt[b[i]]++;
  }
  int spe = 1, dif = fir.size();
  f = 0, mode = 0;
  // dif: number of different colors.
  while (cnt[spe]) spe++;
  for (int i = 1; i <= n + 1; i++) {
    if (cnt[i] > f) {
      f = cnt[i];
      mode = i;
    }
  }
  if (x < f + f - n - (n - y)) {
    puts("NO");
    return;
  }
  if (x == n - 1) {
    if (y == n) {
      puts("NO");
      return;
    }
    make(n);
    a[n] = spe;
    puts("YES");
    for (int i = 1; i <= n; i++)
      printf("%d%c", a[i], i == n ? '\n' : ' ');
    return;
  }
  if (dif == 2 && y == n && ((n - x) & 1)) {
    puts("NO");
    return;
  }
  int xx = max(f + f - n, x), yy = n;
  if (dif == 2 && ((n - xx) & 1)) xx++;
  make(xx);
  vector<int> same, diff;
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) same.push_back(i);
    else diff.push_back(i);
  }
  while (xx > x) {
    a[same.back()] = spe;
    same.pop_back();
    xx--, yy--;
  }
  while (yy > y) {
    a[diff.back()] = spe;
    diff.pop_back();
    yy--;
  }
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? '\n' : ' ');
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}