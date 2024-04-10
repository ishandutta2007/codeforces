// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 100005;
const int inf = 1e9;

struct MAT {
  int v[3][3];
} A, B, C;

char a[N];
int n, q;

#define ls (u << 1)
#define rs (u << 1 | 1)

MAT tr[N << 2];
MAT operator * (MAT a, MAT b) {
  MAT ans;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ans.v[i][j] = 1e9;
      for (int k = 0; k < 3; k++) {
        ckmin(ans.v[i][j], a.v[i][k] + b.v[k][j]);
      }
    }
  }
  return ans;
}
void build(int u, int l, int r) {
  if (l == r) {
    switch (a[l]) {
      case 'a': tr[u] = A; break;
      case 'b': tr[u] = B; break;
      case 'c': tr[u] = C; break;
    }
    return ;
  }
  int mid = l + r >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  tr[u] = tr[ls] * tr[rs];
}
void update(int u, int l, int r, int pos) {
  if (l == r) {
    switch (a[l]) {
      case 'a': tr[u] = A; break;
      case 'b': tr[u] = B; break;
      case 'c': tr[u] = C; break;
    }
    return ;
  } 
  int mid = l + r >> 1;
  if (pos <= mid) update(ls, l, mid, pos);
  else update(rs, mid + 1, r, pos);
  tr[u] = tr[ls] * tr[rs];
}

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", a + 1);
  A.v[0][0] = 1, A.v[1][0] = inf, A.v[2][0] = inf;
  A.v[0][1] = 0, A.v[1][1] = 0, A.v[2][1] = inf;
  A.v[0][2] = inf, A.v[1][2] = 1, A.v[2][2] = 0;
  
  B.v[0][0] = 0, B.v[1][0] = inf, B.v[2][0] = inf;
  B.v[0][1] = 1, B.v[1][1] = 1, B.v[2][1] = inf;
  B.v[0][2] = inf, B.v[1][2] = 0, B.v[2][2] = 0;
  
  C.v[0][0] = 0, C.v[1][0] = inf, C.v[2][0] = inf;
  C.v[0][1] = 1, C.v[1][1] = 0, C.v[2][1] = inf;
  C.v[0][2] = inf, C.v[1][2] = 1, C.v[2][2] = 1;
  
  build(1, 1, n);
  while (q--) {
    int pos = read();
    char ch = getchar();
    while (ch < 'a' || ch > 'c') ch = getchar();
    a[pos] = ch;
    update(1, 1, n, pos);
    print(min({tr[1].v[0][0], tr[1].v[0][1], tr[1].v[0][2]}), '\n');
  }
}