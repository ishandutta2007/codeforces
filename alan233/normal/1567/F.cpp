// Author: wlzhouzhuan
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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

const int N = 505;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

void WA(int type) { puts("NO"),/* printf("type %d\n", type),*/ exit(0); }

char a[N][N];
int n, m;

int id(int i, int j) { return (i - 1) * m + j; }

vector<int> adj[N * N];
int col[N * N], ans[N][N];
void add(int u, int v) {
  adj[u].pb(v), adj[v].pb(u);
}
void dfs(int u) {
  for (auto v: adj[u]) {
    if (!col[v]) {
      col[v] = col[u] ^ 5;
      dfs(v);
    } else if (col[v] != (col[u] ^ 5)) {
      assert(0);
      WA(1);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  rep(i, 1, n) {
    scanf("%s", a[i] + 1);
  } 
  rep(i, 1, n) {
    rep(j, 1, m) if (a[i][j] == 'X') {
      vector<int> go;
      rep(d, 0, 3) {
        int fi = i + dx[d], fj = j + dy[d];
        if (a[fi][fj] != '.') continue;
        go.pb(id(fi, fj));
      }
      if (SZ(go) & 1) /*printf("i = %d, j = %d\n", i, j), */WA(0);
      rep(k, 1, SZ(go) - 1) add(go[k], go[k - 1]);
    }
  }
  rep(i, 1, n) {
    rep(j, 1, m) if (a[i][j] != 'X' && !col[id(i, j)]) {
      col[id(i, j)] = 1;
      dfs(id(i, j));
    }
  }
  rep(i, 1, n) {
    rep(j, 1, m) if (a[i][j] != 'X') {
      ans[i][j] = col[id(i, j)];
    }
  }
  rep(i, 1, n) {
    rep(j, 1, m) if (a[i][j] == 'X') {
      rep(d, 0, 3) {
        int fi = i + dx[d], fj = j + dy[d];
        if (a[fi][fj] != '.') continue;
        ans[i][j] += ans[fi][fj];
      }
      assert(ans[i][j] % 5 == 0);
    }
  }
  puts("YES");
  rep(i, 1, n) {
    rep(j, 1, m) {
      print(ans[i][j], " \n"[j == m]);
    }
  }
  return 0;
}

/*
24 24
........................
..........X....X.....XX.
.........X....X.X...XXX.
........X....X.X...XXX..
.......X......X....XX...
........................
........................
..X.....X.X...XX....XXX.
.X.X...X.....XXXX..XX.X.
..X.X.....X..XXXX..X.XX.
...X...X.X....XX...XXX..
........................
........................
.X.....X..X..X.X...X.XX.
..X.....XX......X....XX.
...X....XX...X.....XX...
....X..X..X...X.X..XX.X.
........................
........................
.XX....XX...............
.XX....XX...............
........................
........................
........................
*/