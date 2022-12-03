/*


Q.E.D.

start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 300005
int n, m, x[maxn], mat[maxn], ans[maxn];
char dir[maxn];

bool cmp(const int &a, const int &b) {
  return x[a] < x[b];
}

void work(vector<int> &vec) {
  sort(vec.begin(), vec.end(), cmp);
  deque<int> stk;
  for (auto i : vec) {
    if (dir[i] == 'L') {
      if (stk.size() && dir[stk.back()] == 'R') {
        mat[i] = stk.back();
        mat[stk.back()] = i;
        stk.pop_back();
      } else {
        stk.push_back(i);
      }
    } else {
      stk.push_back(i);
    }
  }
  while (stk.size() >= 2 && dir[stk[1]] == 'L') {
    mat[stk[0]] = stk[1];
    mat[stk[1]] = stk[0];
    stk.pop_front();
    stk.pop_front();
  }
  while (stk.size() >= 2 && dir[stk[stk.size() - 2]] == 'R') {
    int foo = stk.back();
    stk.pop_back();
    int bar = stk.back();
    stk.pop_back();
    mat[foo] = bar;
    mat[bar] = foo;
  }
  if (stk.size() == 2) {
    mat[stk[0]] = stk[1];
    mat[stk[1]] = stk[0];
  }
}

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    mat[i] = 0;
    scanf("%d", x + i);
  }
  for (int i = 1; i <= n; i++) {
    char tmp[5];
    scanf("%s", tmp);
    dir[i] = tmp[0];
  }
  vector<int> odd, even;
  for (int i = 1; i <= n; i++) {
    ((x[i] & 1) ? odd : even).push_back(i);
  }
  work(odd); work(even);
  for (int i = 1; i <= n; i++) {
    if (!mat[i]) {
      ans[i] = -1;
      continue;
    }
    int j = mat[i];
    if (x[j] < x[i])
      continue;
    if (dir[i] == 'L') {
      if (dir[j] == 'L') {
        ans[i] = ans[j] = (x[i] + x[j]) / 2;
      } else {
        ans[i] = ans[j] = (x[i] + m - x[j] + m) / 2;
      }
    } else {
      if (dir[j] == 'L') {
        ans[i] = ans[j] = (x[j] - x[i]) / 2;
      } else {
        ans[i] = ans[j] = (m - x[i] + m - x[j]) / 2;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d%c", ans[i], i == n ? '\n' : ' ');
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}