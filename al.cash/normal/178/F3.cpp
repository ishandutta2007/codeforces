#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;

void smax(int &a, int b) { if(a < b) a = b; }

const int h = 2002;

int n, k, lcp[h];
string s[h];

vi f(int l, int r) {
  if (l + 1 == r) return vi(2, 0);
  vi x(r - l + 1, 0);
  int m = l;
  FOR(i, l, r-1) if(lcp[i] < lcp[m]) m = i;
  vi a = f(l, m+1);
  vi b = f(m+1, r);
  REP(i, sz(a)) REP(j, sz(b)) smax(x[i+j], a[i] + b[j] + lcp[m] * i * j);
  return x;
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  char c[555];
  REP(i, n) {
    scanf("%s", c);
    s[i] = c;
  }
  sort(s, s+n);
  REP(i, n-1) {
    int j = 0;
    while (j<sz(s[i]) && j<sz(s[i+1]) && s[i][j]==s[i+1][j]) ++j;
    lcp[i] = j;
  }
  vi ans = f(0, n);
  printf("%d\n", ans[k]);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}