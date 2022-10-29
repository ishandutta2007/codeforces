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

const int N = 1e5+5;
int n, p[N];
bool us[N];
vector<vi> c;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) scanf("%d", p+i), --p[i];

  int m = -1;
  REP(i, n) if (!us[i]) {
    int j = i;
    vi t;
    while (true) {
      t.pb(j);
      us[j] = true;
      j = p[j];
      if (j == i) break;
    }
    if (m == -1 || sz(t) < sz(c[m])) m = sz(c);
    c.pb(t);
  }

  int l = sz(c[m]);
  bool ok = l <= 2;
  REP(i, sz(c)) if (sz(c[i]) % l != 0) {
    ok = false;
    break;
  }

  if (ok) {
    printf("YES\n");
    if (sz(c[m]) == 2) printf("%d %d\n", c[m][0]+1, c[m][1]+1);
    REP(i, sz(c)) if (i != m) {
      REP(j, sz(c[i])) printf("%d %d\n", c[i][j]+1, c[m][j%l]+1);
    }
  } else {
    printf("NO\n");
  }

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}