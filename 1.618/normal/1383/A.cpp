#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 100005
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<char, char> P;

int n;
char s[maxn], t[maxn]; 
void solve() {
  scanf("%d", &n);
  scanf("%s%s", s + 1, t + 1);
  int ans = 0;
  while (true) {
    P low = mp('z', 'z');
    for (int i = 1; i <= n; i++) {
      if (s[i] != t[i]) {
        low = min(low, mp(s[i], t[i]));
      }
    }
    if (low.first > low.second) {
      puts("-1");
      return;
    }
    if (low.first == 'z') break;
    ans++;
    for (int i = 1; i <= n; i++) {
      if (s[i] != t[i] && s[i] == low.first) s[i] = low.second;
    }
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}