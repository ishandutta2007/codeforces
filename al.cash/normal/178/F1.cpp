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

int n, k;
string s[h];

vi f(int l, int r, int d) {
  if (l+1==r) return vi(2, 0);
  int l0 = l;
  vi a(r-l+1, 0);
  int m = sz(a)-1;
  vi t;
  while(l<r && sz(s[l])==d) ++l;
  FOR(i, l+1, r+1) if(i==r || s[i-1][d] != s[i][d]) {
    t = f(l, i, d+1);
    FOR(j, 2, sz(t)) t[j] += j*(j-1)/2;
    FORD(u, m, 0) FOR(j, 1, min(sz(t), sz(a)-u))
      smax(a[u+j], a[u] + t[j]);
    //m = min(sz(a)-1, m + sz(t));
    l = i;
  }
  //printf("%d %d %d:", l0, r, d); REP(i, sz(a)) printf(" %d", a[i]); printf("\n");
  return a;
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
  vi ans = f(0, n, 0);
  printf("%d\n", ans[k]);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}