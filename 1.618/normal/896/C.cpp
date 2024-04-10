/*
start thinking:
BULB:
result of thinking: Pure.

CF896C, ODT , .

OI-wiki  ODT  key ,  split  erase,
 split  split .
 key,  split 
,  split .

 https://zhuanlan.zhihu.com/p/102786071 , 
O(m)  set::lower_bound, O(m + n) . m  set::size()
 O(log n),  O(n log log n).

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

int seed, vmax;
int rng() {
  int ret = seed;
  seed = (seed * 7ll + 13) % 1000000007;
  return ret;
}

#define maxn 100005
int n, m;
ll val[maxn];
set<int> ls;

int modpow(int x, int y, int mod) {
  int res = 1;
  while (y) {
    if (y & 1)
      res = (ll)res * x % mod;
    y >>= 1;
    x = (ll)x * x % mod;
  }
  return res;
}

auto split(int x) {
  auto nxt = ls.upper_bound(x), it = prev(nxt);
  if (*it == x)
    return it;
  val[x] = val[*it];
  return ls.insert(x).first;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d%d%d", &n, &m, &seed, &vmax);
  for (int i = 1; i <= n; i++) {
    int a = rng() % vmax + 1;

    // cout << a << " ";

    val[i] = a;
    ls.insert(i);
  }

  // cout << endl;
  // system("pause");

  ls.insert(n + 1);
  for (int i = 1; i <= m; i++) {
    int op = (rng() & 3) + 1, l = rng() % n + 1, r = rng() % n + 1, x, y;
    if (l > r)
      swap(l, r);
    if (op == 3)
      x = rng() % (r - l + 1) + 1;
    else
      x = rng() % vmax + 1;
    if (op == 4)
      y = rng() % vmax + 1;
    
    // cout << op << " " << l << " " << r << " " << x << " ";
    // if (op == 4)
    //   cout << y << " ";
    // cout << endl;
    // system("pause");

    auto itl = split(l), itr = split(r + 1);
    if (op == 1) {
      for (; itl != itr; itl++) {
        val[*itl] += x;
      }
    } else if (op == 2) {
      val[*itl] = x;
      ls.erase(++itl, itr);
    } else if (op == 3) {
      vector<pair<ll, int>> foo;
      for (; itl != itr; itl++) {
        foo.push_back({val[*itl], *next(itl) - *itl});
      }
      sort(foo.begin(), foo.end());
      for (auto j : foo) {
        if (x <= j.second) {
          printf("%lld\n", j.first);
          break;
        }
        x -= j.second;
      }
    } else {
      int ans = 0;
      for (; itl != itr; itl++) {
        ans = (ans + (ll)modpow(val[*itl] % y, x, y) * (*next(itl) - *itl)) % y;
      }
      printf("%d\n", (ans + y) % y);
    }

    // for (auto i : ls)
    //   cout << i << " ";
    // cout << endl;
    // for (auto i : ls)
    //   cout << val[i] << " ";
    // cout << endl;
    // system("pause");

  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}