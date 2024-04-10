#include <bits/stdc++.h>
using namespace std;

int a[104][104], n, m;
char s[104];

vector<pair<int, int> > ans;

void dd(int t, int b, int c, int d, int e, int f) {
  ans.push_back(make_pair(t, b));
  ans.push_back(make_pair(c, d));
  ans.push_back(make_pair(e, f));
  a[t][b] ^= 1;
  a[c][d] ^= 1;
  a[e][f] ^= 1;
}

void Main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++) {
      a[i][j] = s[j] == '1';
    }
  }
  ans.clear();
  for (int i = n; i >= 3; i--) {
    for (int j = m; j >= 2; j--) {
      if (a[i][j] == 1) {
        dd(i - 1, j - 1, i - 1, j, i, j);
      }
    }
    if (a[i][1] == 1) {
      dd(i - 1, 1, i - 1, 2, i, 1);
    }
  }
  for (int j = m; j >= 3; j--) {
    if (a[1][j] == 1) {
      dd(1, j - 1, 2, j - 1, 1, j);
    }
    if (a[2][j] == 1) {
      dd(1, j - 1, 2, j - 1, 2, j);
    }
  }
  if (a[1][1] + a[1][2] + a[2][1] + a[2][2] == 4) {
    dd(1,1,1,2,2,1);
  }
  if (a[1][1] + a[1][2] + a[2][1] + a[2][2] == 1) {
    if (a[1][1]) {
      dd(1,1,1,2,2,1);
    } else if (a[1][2]) {
      dd(1,1,1,2,2,2);
    } else if (a[2][1]) {
      dd(1,1,2,1,2,2);
    } else if (a[2][2]) {
      dd(1,2,2,1,2,2);
    }
  }
  if (a[1][1] + a[1][2] + a[2][1] + a[2][2] == 2) {
    if (a[1][1] & a[2][2]) {
      dd(1,1,1,2,2,1);
    } else if (a[1][2] & a[2][1]) {
      dd(1,1,1,2,2,2);
    } else if (!a[1][1]) {
      dd(1,1,1,2,2,1);
    } else if (!a[1][2]) {
      dd(1,1,1,2,2,2);
    } else if (!a[2][1]) {
      dd(1,1,2,1,2,2);
    } else if (!a[2][2]) {
      dd(1,2,2,1,2,2);
    }
  }
  if (a[1][1] + a[1][2] + a[2][1] + a[2][2] == 3) {
    if (!a[2][2]) {
      dd(1,1,1,2,2,1);
    } else if (!a[2][1]) {
      dd(1,1,1,2,2,2);
    } else if (!a[1][2]) {
      dd(1,1,2,1,2,2);
    } else if (!a[1][1]) {
      dd(1,2,2,1,2,2);
    }
  }
  printf("%d\n", ans.size() / 3);
  for (int i = 0; i < (int) ans.size(); i += 3) {
    printf("%d %d %d %d %d %d\n", ans[i].first, ans[i].second, ans[i + 1].first, ans[i + 1].second, ans[i + 2].first, ans[i + 2].second);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    Main();
  }
}