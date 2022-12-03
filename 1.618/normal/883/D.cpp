#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 1000005
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;

int n;
char s[maxn];
int sumAst[maxn], f[maxn];
vector<int> posP;

namespace OneP {
  P solveL(int pos) {
    int num = sumAst[pos], tim = pos - 1;
    for (int i = 1; i < pos && s[i] == '.'; i++) tim--;
    return mp(num, -tim);
  }
  P solveR(int pos) {
    int num = sumAst[n] - sumAst[pos], tim = n - pos;
    for (int i = n; i > pos && s[i] == '.'; i--) tim--;
    return mp(num, -tim);
  }
  void solve() {
    P ans = max(solveL(posP.back()), solveR(posP.back()));
    printf("%d %d\n", ans.first, -ans.second);
  }
}

bool none(int l, int r) {
  return l > r || sumAst[r] - sumAst[l - 1] == 0;
}
bool check(int t) {
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= (int)posP.size(); i++) {
    if (none(f[i - 1] + 1, posP[i - 1] - t - 1))
      f[i] = max(f[i], posP[i - 1]);
    if (none(f[i - 1] + 1, posP[i - 1] - 1))
      f[i] = max(f[i], posP[i - 1] + t);
    if (i >= 2 && posP[i - 1] - t < posP[i - 2] && none(f[i - 2] + 1, posP[i - 1] - t - 1))
      f[i] = max(f[i], posP[i - 2] + t);
  }
  return none(f[posP.size()] + 1, n);
}

int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    sumAst[i] = sumAst[i - 1] + (s[i] == '*');
    if (s[i] == 'P') posP.push_back(i);
  }
  if (posP.size() == 1) OneP::solve();
  else {
    int lb = 1, rb = n;
    while (lb < rb) {
      int mid = (lb + rb) >> 1;
      if (check(mid)) rb = mid;
      else lb = mid + 1;
    }
    printf("%d %d\n", sumAst[n], lb);
  }
  return 0;
}