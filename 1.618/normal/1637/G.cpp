/*
start thinking:
BULB:
result of thinking: Pure.

n>=3m = 2^{ceil(log_2{n})}.
: 2<m>1
0<m.

start coding:
AC:

[n, m)! ****, nx,
pn (x, y) -> ((x + y) / 2, |x - y| / 2)p
n1.
#.
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;


int toPow2(int x) {
  if (x == 1)
    return 1;
  return 1 << (32 - __builtin_clz(x - 1));
}

void solve() {
  int n;
  scanf("%d", &n);
  if (n == 2) {
    puts("-1");
    return;
  }
  vector<P> ans;
  multiset<int> S, T, U;
  for (int i = 1; i <= n; i++)  
    S.insert(i);
  while (S.size()) {
    int foo = *S.rbegin();
    if (!foo) {
      T.insert(foo);
      S.erase(--S.end());
    }
    int bar = toPow2(foo);
    if (foo == bar) {
      T.insert(foo);
      S.erase(--S.end());
    } else {
      vector<int> lis;
      while (*S.rbegin() > (bar >> 1)) {
        ans.push_back({*S.rbegin(), bar - *S.rbegin()});
        lis.push_back(*S.rbegin());
        S.erase(S.find(bar - *S.rbegin()));
        S.erase(--S.end());
      }
      for (auto i : lis) {
        S.insert(2 * i - bar);
        T.insert(bar);
      }
    }

    // for (auto i : S) {
    //   cout << i << " ";
    // }
    // cout << endl;
    // system("pause");

  }

  // for (auto i : T) {
  //   cout << i << " ";
  // }
  // cout << endl;
  // system("pause");

  while (T.size() >= 2) {
    int foo = *T.begin(), bar = *(++T.begin());
    if (!foo || foo >= n || foo != bar) {
      T.erase(T.begin());
      U.insert(foo);
    } else {
      ans.push_back({foo, bar});
      T.erase(T.begin());
      T.erase(T.begin());
      U.insert(0);
      T.insert(foo + bar);
    }
  }
  while (T.size()) {
    U.insert(*T.begin());
    T.erase(T.begin());
  }
  while (true) {
    int foo = *U.lower_bound(1);
    if (foo >= n)
      break;
    int bar = *(++U.lower_bound(1));
    if (foo < bar) {
      ans.push_back({0, foo});
      ans.push_back({foo, foo});
      U.erase(foo);
      U.insert(foo << 1);
    } else {
      ans.push_back({foo, foo});
      U.erase(U.find(foo));
      U.erase(U.find(foo));
      U.insert(0);
      U.insert(foo << 1);
    }
  }
  int foo = *U.rbegin(), cnt = U.count(0);
  while (cnt--)
    ans.push_back({0, foo});
  printf("%d\n", (int)ans.size());
  for (auto i : ans) {
    printf("%d %d\n", i.first, i.second);
  }
}

bool Med;
int main() {
  // freopen("G.in", "r", stdin);
  // freopen("G.out", "w", stdout);
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}