#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* separator = " ", const char* closing = "\n") {
  for (Iterator it = begin; it != end; printf(fmt, *it),
       printf("%s", ++it == end ? closing : separator));
}

const int N = 2e5+5;
int n;
char s[N];
bool l[N];

typedef pair<int, vi> pivi;

pivi solve(bool first, bool last) {
  int no = 0;
  while (l[no] != first) ++no;
  vi u(n, -1);
  vi e(l, l + n);
  deque<int> a[2];
  FORD(i, n-1, 0) {
    bool w = l[i]^1;
    if (!a[w].empty() && a[w].front() != no) {
      u[i] = a[w].front();
      a[w].pop_front();
      e[i] = e[u[i]];
    }
    a[l[i]].pb(i);
  }
//  print("%d", all(u));
  REP(w, 2) partition(all(a[w]), [&e, &last](int i) { return e[i] == last; });
//  printf("target: %d -> %d\n", (int)first, (int)last);
//  REP(w, 2) for (auto i : a[w]) printf("%d(%d) -> %d\n", w, (int)l[i], (int)e[i]);
  int sum = sz(a[0]) + sz(a[1]);
  int ans = sum - 1;
  vi p;
  p.reserve(n);
  for (; sum > 0; --sum) {
    int v = a[first].back();
    a[first].pop_back();
    first = e[v]^1;
    while (v != -1) {
      p.pb(v + 1);
      v = u[v];
    }
  }
  return {ans, p};
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%s", s);
  n = strlen(s);
  REP(i, n) l[i] = s[i] == 'L';
  pivi ans;
  if (n&1) {
    int kl = 0;
    REP(i, n) {
      if (l[i]) ++kl;
      else --kl;
    }
    ans = solve(kl > 0, kl > 0);
  } else {
    ans = solve(true, false);
    pivi t = solve(false, true);
    if (t.X < ans.X) ans = t;
  }
  printf("%d\n", ans.X);
  print("%d", all(ans.Y));

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}