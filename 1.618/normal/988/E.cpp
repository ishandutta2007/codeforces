#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 25
using namespace std;
typedef long long ll;
typedef long double ldouble;
const int LEN = 100000;

char s[maxn];
int n, a[maxn];
vector<int> pos[15];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
  for (int i = n; i >= 1; i--) pos[a[i]].push_back(n - i);
  int ans = 10000, len0 = 0;
  while (len0 < n - 1 && a[1 + len0 + 1] == 0) len0++; 
  if (len0 == n - 1) {
    if (n >= 3) puts("0");
    else if (n == 2 && a[1] == 5) puts("0");
    else puts("-1");
    return 0;
  }
  
  if (pos[0].size() >= 2) {
    ans = min(ans, pos[0][0] + pos[0][1] - 1);
  }
  
  if (pos[2].size() && pos[5].size()) {
    ans = min(ans, pos[2][0] + pos[5][0] - 1
                + (pos[2][0] < pos[5][0])
                + (max(pos[2][0], pos[5][0]) == n - 1) * len0
                + (max(pos[2][0], pos[5][0]) == n - 1
                   && pos[2][0] == 1 && pos[5][0] == 3) * len0);
  }
  
  if (pos[5].size() && pos[0].size()) {
    ans = min(ans, pos[0][0] + pos[5][0] - 1
                + (pos[5][0] < pos[0][0])
                + (pos[5][0] == n - 1) * len0
                - (pos[5][0] == n - 1 && pos[0][0] == n - len0 - 1));
  }
  
  if (pos[7].size() && pos[5].size()) {
    ans = min(ans, pos[7][0] + pos[5][0] - 1
                + (pos[7][0] < pos[5][0])
                + (max(pos[7][0], pos[5][0]) == n - 1) * len0
                + (max(pos[7][0], pos[5][0]) == n - 1
                   && pos[7][0] == 1 && pos[5][0] == 3) * len0);
  }
  
  printf("%d\n", ans == 10000 ? -1 : ans);
  return 0;
}