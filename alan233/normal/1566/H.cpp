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

//#define zz
//#define DEBUG
//#define DEBUG2

const int N = 1000005;

int C, n;

vector<int> xay_ask;
// f[i]  pset = i  xor 
// g[i]  gcd(pset, i) != 1  xor 
int f[N], g[N], all_xor;

vector<int> fset[N]; // fset[i]  pset[j] = i  j  
int pset[N], pr[N >> 2], plen; bool pvis[N];
void xxs(int n) {
  pvis[1] = 1, pset[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!pvis[i]) pr[++plen] = i, pset[i] = i;
    for (int j = 1; j <= plen && pr[j] * i <= n; j++) {
      pvis[pr[j] * i] = 1;
      if (i % pr[j] == 0) {
        pset[pr[j] * i] = pset[i];
        break;
      }
      pset[pr[j] * i] = pset[i] * pr[j];
    } 
  }
//  for (int i = 1; i <= n; i++) {
////    printf("pset[%d] = %d\n", i, pset[i]);
//    int ii = i, qwq = 1;
//    for (int j = 2; j <= ii; j++) {
//      if (ii % j == 0) {
//        while (ii % j == 0) ii /= j;
//        qwq *= j;
//      }
//    }
//    if (pset[i] != qwq) {
//      printf("%d %d\n", pset[i], qwq);
//    }
//    assert(pset[i] == qwq);
//  }
  for (int i = 1; i <= n; i++) {
    fset[pset[i]].pb(i);
    if (pset[i] == i) {
      xay_ask.pb(i);
    }
  } 
}

/*
struct LBase {
  int a[21], who[21];
  LBase() { mset(a, 0), mset(who, 0); }
  bool ins(int x, int y) {
    for (int i = 20; i >= 0; i--) {
      if (x >> i & 1) {
        if (!who[i]) {
          a[i] = x, who[i] = y;
          return 1;
        }
        x ^= a[i];
      }
    }
    return 0;
  }
  vector<int> query(int x) {
    vector<int> chose;
    for (int i = 20; i >= 0; i--) {
      if (x >> i & 1) {
        if (!who[i]) assert(0); // !!! 
        chose.pb(who[i]);
        x ^= a[i];
      }
    } 
    return chose;
  }
};
*/

vector<int> ans;

struct node {
  vector<int> chose;
  int sz;
};
vector<node> bag[N];
 
const int BOUND = 300;

void solve(int x) {
//  printf("x = %d, fset = ", x); for (auto v: fset[x]) printf("%d ", v); puts("");
  vector<int> num = fset[x];
  
  assert(SZ(num) < BOUND);
  
  vector<bool> in_bs(SZ(num));
  vector<bitset<BOUND>> xor_by(SZ(num));
  bitset<BOUND> bs_xor_by[21]; int bs_v[21]; mset(bs_v, 0);
  for (int i = 0; i < SZ(num); i++) assert(!xor_by[i].count());
  for (int i = 0; i < SZ(num); i++) xor_by[i].set(i);
  bool IAKIOI = 0;
  for (int i = 0; i < SZ(num); i++) {
    bool ac = 0;
    for (int j = 20; j >= 0; j--) {
      if (num[i] >> j & 1) {
        if (!bs_v[j]) {
          bs_v[j] = num[i];
          bs_xor_by[j] = xor_by[i];
          ac = 1;
          break;
        }
        num[i] ^= bs_v[j];
        xor_by[i] ^= bs_xor_by[j];
      }
    }
    in_bs[i] = ac;
    if (!ac) IAKIOI = 1;
  }
  if (!IAKIOI) {
    static int times = 0; ++times;
    #ifdef DEBUG2
    printf("x = %d, IAKIOI times = %d\n", x, times);
    #endif
    bitset<BOUND> all_xor_by;
    int X = f[x];
    for (int j = 20; j >= 0; j--) {
      if (X >> j & 1) {
        X ^= bs_v[j];
        all_xor_by ^= bs_xor_by[j];
      }
    } 
    assert(!X);
    int __ = 0;
    for (int i = 0; i < SZ(num); i++) {
      if (all_xor_by.test(i))
        ans.pb(fset[x][i]), __ ^= fset[x][i], assert(pset[fset[x][i]] == x);
    }
//    printf("__ = %d, f[x] = %d\n", __, f[x]);
    assert(__ == f[x]);
    return ;
  }
  
  vector<bool> diff_sz(SZ(num) + 1);
  
  int random_times = 8;
  while (random_times--) {
    bitset<BOUND> all_xor_by;
    int X = f[x];
    for (int i = 0; i < SZ(num); i++) {
      if (!in_bs[i]) {
//        assert(num[i] == 0);
        if (rand() & 1) {
          X ^= num[i];
          all_xor_by ^= xor_by[i]; 
        }
      }
    }
    for (int j = 20; j >= 0; j--) {
      if (X >> j & 1) {
        assert(bs_v[j] >> j & 1);
        X ^= bs_v[j];
        all_xor_by ^= bs_xor_by[j];
      }
    }
    assert(!X);
    vector<int> chose;
    
    int __ = 0;
    for (int i = 0; i < SZ(num); i++) {
      if (all_xor_by.test(i))
        chose.pb(fset[x][i]), __ ^= fset[x][i], assert(pset[fset[x][i]] == x);
    }
    assert(__ == f[x]);
    
//    if (chose.empty()) continue;
    if (diff_sz[SZ(chose)]) continue; // 
    diff_sz[SZ(chose)] = 1; 
    bag[x].pb({chose, SZ(chose)});
  }
} 

namespace ZZ {
int a[N];
void get_answer(vector<int> ask) {
  for (auto v: ask) {
    int X = 0;
    for (int i = 1; i <= n; i++) {
      if (__gcd(a[i], v) == 1) {
        X ^= a[i];
      }
    }
    g[v] = X;
//    printf("g[%d] = %d\n", v, g[v]);
  }
} 
void check(vector<int> ask) {
  for (auto v: ask) {
//    if (v == 1) continue;
    int X = 0;
    for (int i = 1; i <= n; i++) {
      if (pset[a[i]] == v) {
        X ^= a[i];
      }
    }
    assert(X == f[v]);
  }
}
void check_ans(vector<int> ans) {
  assert(SZ(ans) == n);
  for (int i = 1; i <= n; i++) a[i] = ans[i - 1];
  for (auto v: xay_ask) {
//    if (v == 1) continue;
    int X = 0;
//    for (int i = 1; i <= n; i++) {
//      if (__gcd(v, a[i]) == 1) {
//        X ^= a[i];
//      }
//    }
    for (int i = 1; i <= n; i++) {
      if (pset[a[i]] == v) {
        X ^= a[i];
      }
    }
    if (X != f[v]) {
      printf("WA on v = %d\n", v);
      printf("expected = %d, yours = %d\n", f[v], X);
    }
    assert(X == f[v]);
  }
}
}

bitset<35000> dp[8000];

int main() {
  
//  freopen("data.in", "r", stdin);
  
  scanf("%d%d", &C, &n);
  
  #ifdef zz
  for (int i = 1; i <= n; i++) ZZ::a[i] = read();
  #endif
  
  
//  for (int i = 1; i <= n; i++) ans.pb(ZZ::a[i]);
//  ZZ::check(ans);
//  ans.clear();
  
  xxs(C);
  
  #ifdef zz
  ZZ::get_answer(xay_ask);
  #else
  printf("%d ", SZ(xay_ask));
  for (auto v: xay_ask) printf("%d ", v); puts(""), fflush(stdout);
  for (auto v: xay_ask) scanf("%d", &g[v]);
  #endif
  
  #ifdef DEBUG
  for (int i = 1; i <= C; i++) {
    printf("g[%d] = %d\n", i, g[i]);
  }
  #endif
  
  all_xor = g[1];
  for (auto i: xay_ask) {
    for (int j = i; j <= C; j += i) {
      if (pset[j] == j)
      f[j] ^= (g[i] ^ all_xor);
    }
  }
  
  reverse(xay_ask.begin(), xay_ask.end());
  f[1] = all_xor; 
//  xay_ask.pop_back(); // 1  
  for (auto i: xay_ask) {
    for (int j = 2 * i; j <= C; j += i) {
      if (pset[j] == j)
        f[i] ^= f[j];
    }
  }
  reverse(xay_ask.begin(), xay_ask.end());
  
  #ifdef DEBUG2
  for (auto v: xay_ask) {
    printf("f[%d] = %d\n", v, f[v]);
  } 
  puts("-----");
  #endif 
  
//  return 0; // !!!
  
  #ifdef zz
  ZZ::check(xay_ask);
  #endif
  
//  for (auto v: xay_ask) {
//    printf("f[%d] = %d\n", v, f[v]);
//  }
  
  for (auto v: xay_ask) {
//    if (v == 1) continue;
    solve(v);
    #ifdef DEBUG
    printf("x = %d, can sz = ", v);
    for (auto it: bag[v]) {
      printf("%d ", it.sz);
    }
    puts("");
    #endif
  }
  
  #ifdef DEBUG
  printf("prework, ans.size = %d\n", SZ(ans));
  #endif
  
  int new_n = n - SZ(ans);
  #ifdef DEBUG
  printf("new_n = %d\n", new_n); 
  #endif
  
//  #ifdef DEBUG2
//  printf("new_n = %d\n", new_n); 
//  #endif

  vector<int> emm;
  int l = 0;
  
  dp[0].set(0);
  for (int i = 1; i <= SZ(xay_ask); i++) {
    if (bag[xay_ask[i - 1]].empty()) {
//      dp[i] = dp[i - 1];
      continue;
    }
    ++l, emm.pb(xay_ask[i - 1]);
    for (auto v: bag[xay_ask[i - 1]]) {
      dp[l] |= dp[l - 1] << v.sz;
    }
  }
//  printf("l = %d\n", l); 
//  if (dp[SZ(xay_ask) - 1][new_n] == 0) {
//    cerr << "!!!\n";
//    ans.pb(1);
//    new_n--;
//  }
  assert(dp[l][new_n] || dp[l][new_n]);
  for (int i = l; i >= 1; i--) {
    for (auto v: bag[emm[i - 1]]) {
      if (new_n - v.sz >= 0 && dp[i - 1].test(new_n - v.sz)) {
        new_n -= v.sz;
        int __ = 0;
        for (auto _: v.chose) ans.pb(_), __ ^= _;
//        assert(__ == f[xay_ask[i - 1]]);
//        printf("debug %d\n", xay_ask[i]);
        break;
      }
    }
  }
  
//  sort(ans.begin(), ans.end());

  #ifndef zz
  for (auto v: ans) printf("%d ", v);
  puts(""), fflush(stdout);
  #endif
  
  #ifdef zz
  ZZ::check_ans(ans);
  #endif
  return 0;
}

/*
10 6
1 4 5 6 8 10
*/

/*
100 10
4 17 20 28 66
80 90 95 96 97
*/