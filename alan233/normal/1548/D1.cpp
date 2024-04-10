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

const ll mod = 1e18;
int cnt[2][2];
int n;
ll ans;

int check(int x1, int x2, int y1, int y2) {
  if (x1 == y1 && x2 == y2) 
    return 0;
  else
    return 2;
}

ll C3(int x) { return 1ll * x * (x - 1) * (x - 2) / 6 % mod;  }
ll C2(int x) { return 1ll * x * (x - 1) / 2 % mod; }

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    cnt[(x % 4) / 2][(y % 4) / 2]++;    
  }
  for (int x = 0; x < 4; x++) {
    for (int y = x; y < 4; y++) {
      for (int z = y; z < 4; z++) {
        int x1 = x / 2, x2 = x % 2, y1 = y / 2, y2 = y % 2, z1 = z / 2, z2 = z % 2;
        int b = check(x1, x2, y1, y2) + check(y1, y2, z1, z2) + check(z1, z2, x1, x2);
        b %= 4;
        if (!b) {
//          cerr << "!\n";
          if (x == y && y == z) ans = (ans + C3(cnt[x1][x2])) % mod;
          else if (x == y) ans = (ans + 1ll * C2(cnt[x1][x2]) * cnt[z1][z2]) % mod;
          else if (y == z) ans = (ans + 1ll * C2(cnt[y1][y2]) * cnt[x1][x2]) % mod;
          else ans = (ans + 1ll * cnt[x1][x2] * cnt[y1][y2] * cnt[z1][z2]) % mod;
        }
      }
    }
  }
  print(ans, '\n');
  return 0;
}