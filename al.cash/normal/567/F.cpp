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

const int N = 35 * 2;
int n, k;
vector<pair<string, int>> o[N];
ll d[N][N];

ll f(int l, int r);

ll h(int a, int b, int l, int r) {
  int le = l, re = r;
  if (a == l) ++l;
  else --r;
  if (b == l) ++l;
  else --r;
  int v[2] = {a, b};
  REP(i, 2) for (auto& p : o[v[i]]) {
    if (p.X == "=" && p.Y != a && p.Y != b) return 0;
    if (p.X == "<" && (p.Y < l || p.Y > r)) return 0;
    if (p.X == "<=" && (p.Y < le || p.Y > re)) return 0;
    if (p.X == ">" && p.Y >= le && p.Y <= re) return 0;
    if (p.X == ">=" && p.Y >= l && p.Y <= r) return 0;
  }
  return f(l, r);
}

ll f(int l, int r) {
  if (l == r+1) return 1;
  ll& res = d[l][r];
  if (res != -1) return res;
  res = h(l, l+1, l, r);
  if (l+1 < r) {
    res += h(l, r, l, r);
    res += h(r-1, r, l, r);
  }
  return res;
}

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  
  scanf("%d%d", &n, &k);
  REP(i, k) {
    int a, b;
    char s[3];
    scanf("%d%s%d", &a, s, &b);
    --a; --b;
    o[a].eb(s, b);
    if (s[0] != '=') s[0] = s[0] == '<' ? '>' : '<';
    o[b].eb(s, a);
  }
  CL(d, -1);
  cout << f(0, 2*n-1) << endl;
  
#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}