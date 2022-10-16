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

const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;  

int n, m, i, j, k;
int l[N], r[N];
int a[N], rev[N], pos[N], senq[N];  

struct Segment_Tree1 {
  int mn[N << 2]; 
  inline void push_up(int u) {
    mn[u] = std::min(mn[u << 1], mn[u << 1 | 1]);
  }
  void build(int l, int r, int u) {
    if (l == r) {
      mn[u] = l;
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, u << 1);
    build(mid + 1, r, u << 1 | 1);
    push_up(u);
  }
  int range_min(int ql, int qr, int l, int r, int u) {
    //printf("%d %d %d %d %d\n", ql, qr, l, r, u);   
    if (ql <= l && r <= qr) {
      return mn[u];
    }
    int mid = (l + r) >> 1, res = inf;
    if (ql <= mid) {
      res = std::min(res, range_min(ql, qr, l, mid, u << 1));
    }
    if (mid < qr) {
      res = std::min(res, range_min(ql, qr, mid + 1, r, u << 1 | 1));
    }
    return res;
  }   
  void modify(int pos, int l, int r, int u, int val) {
    if (l == r) {
      mn[u] = val;  
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
      modify(pos, l, mid, u << 1, val);
    } else {
      modify(pos, mid + 1, r, u << 1 | 1, val);   
    }
    push_up(u);  
  }
} st1;

struct Segment_Tree2 {
  int mn[N << 2];  
  inline int cmpl(int a, int b) {
    return l[rev[a]] < l[rev[b]] ? a : b;
  }
  inline void push_up(int u) {
    mn[u] = cmpl(mn[u << 1], mn[u << 1 | 1]);
  }
  void build(int l, int r, int u) {
    if (l == r) {
      mn[u] = l;
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, u << 1);
    build(mid + 1, r, u << 1 | 1);
    push_up(u);
  }
  int range_min(int ql, int qr, int l, int r, int u) {
    if (ql <= l && r <= qr) {
      return mn[u];
    }
    int mid = (l + r) >> 1, res = 0;  
    if (ql <= mid) {
      res = cmpl(res, range_min(ql, qr, l, mid, u << 1));  
    }
    if (mid < qr) {
      res = cmpl(res, range_min(ql, qr, mid + 1, r, u << 1 | 1));
    }
    return res;  
  }
} st2;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", l + i, r + i);
    senq[i] = i;
  }
  std::sort(senq + 1, senq + n + 1, [](int a, int b) {
    return r[a] < r[b];
  });
  l[0] = inf;   
  st1.build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    pos[senq[i]] = st1.range_min(l[senq[i]], r[senq[i]], 1, n, 1);  
    //printf("___%d %d %d %d\n", senq[i], l[senq[i]], r[senq[i]], pos[senq[i]]);  
    rev[pos[senq[i]]] = senq[i];
    st1.modify(pos[senq[i]], 1, n, 1, n);
  } 
  st2.build(1, n, 1);    
  int x = -1, y = -1;
  bool flag = 0;
  for (int i = 1, cur; i <= n; i++) {
    //printf("__%d %d %d\n", i + 1, r[rev[i]], rev[st2.range_min(i + 1, r[rev[i]], 1, n, 1)]);    
    if (l[cur = rev[st2.range_min(i + 1, r[rev[i]], 1, n, 1)]] <= i) {
      x = rev[i];
      y = cur;
      flag = 1;
      break;  
    }
  }
  if (!flag) {
    puts("YES");
    for (int i = 1; i <= n; i++) {
      printf("%d%c", pos[i], " \n"[i == n]);
    }
  } else {
    puts("NO");
    for (int i = 1; i <= n; i++) {
      printf("%d%c", pos[i], " \n"[i == n]);
    }
    std::swap(pos[x], pos[y]);
    for (int i = 1; i <= n; i++) {
      printf("%d%c", pos[i], " \n"[i == n]);
    }
  }
  return 0; 
}