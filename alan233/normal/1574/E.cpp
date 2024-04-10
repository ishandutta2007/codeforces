// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
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

const int N = 3000005;
const int mod = 998244353;

int n, m, q;

int pw[N];

int col[N][2], row[N][2];
int banc, banr, freec, freer;
int ban01, ban10;

map<pii, int> s;
void ins(int x, int y, int c) {
  s[{x, y}] = c;
  { //  1  
    if (col[x][(y & 1) ^ c]++ == 0) {
      freec--;
      if (col[x][(y & 1) ^ c ^ 1])
        banc++;
    }
  }
  { //  1  
    if (row[y][(x & 1) ^ c]++ == 0) {
      freer--;
      if (row[y][(x & 1) ^ c ^ 1])
        banr++;
    }
  }
  { // 01
    int t = (x & 1) ^ (y & 1);
    if (t != c) ban01++;
  }
  { // 10
    int t = (x & 1) ^ (y & 1);
    if (t == c) ban10++;
  }
}
void del(int x, int y) {
  if (!s.count({x, y})) return ;
//  D("del %d %d\n", x, y);
  int c = s[{x, y}];
  s.erase({x, y});
  { //  1  
    if (--col[x][(y & 1) ^ c] == 0) {
      freec++;
      if (col[x][(y & 1) ^ c ^ 1])
        banc--;
    }
  }
  { //  1  
    if (--row[y][(x & 1) ^ c] == 0) {
      freer++;
      if (row[y][(x & 1) ^ c ^ 1])
        banr--;
    }
  }
  { // 01
    int t = (x & 1) ^ (y & 1);
    if (t != c) ban01--;
  }
  { // 10
    int t = (x & 1) ^ (y & 1);
    if (t == c) ban10--;
  }
}

int getans() {
//  printf("banc = %d, freec = %d, banr = %d, freer = %d, ban10 = %d, ban01 = %d\n", banc, freec, banr, freer, ban10, ban01);
  int ans = 0;
  { //  1  
    if (!banc) {
      ans = (ans + pw[freec]) % mod;
    }
  }
  { //  1 
    if (!banr) {
      ans = (ans + pw[freer]) % mod;
    } 
  }
  { // 01
    if (!ban01) {
      ans = (ans + mod - 1) % mod;
    }
  }
  { // 10
    if (!ban10) {
      ans = (ans + mod - 1) % mod;
    }
  }
  return ans;
}

int main() {
  pw[0] = 1; rep(i, 1, N - 1) pw[i] = 2 * pw[i - 1] % mod;
  n = read(), m = read(), q = read();
  freec = n, freer = m;
  while (q--) {
    int x = read(), y = read(), opt = read();
    if (opt == -1) del(x, y);
    else {
      if (s.count({x, y})) del(x, y);
      if (opt == 0) ins(x, y, 0);
      else ins(x, y, 1);
    }
    print(getans(), '\n');
  }
  return 0;
}

/*
4 2 3
3 2 0
3 2 -1
3 2 0
*/

/*
4 2 4
1 1 1
4 1 1
2 1 0
4 1 -1
*/