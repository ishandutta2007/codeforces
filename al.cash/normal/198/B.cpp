#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
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
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> void gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

template<class T> void outp(const vector<T>& v) {
  REP(i, sz(v)) cout << v[i] << (i + 1 == sz(v) ? '\n' : ' ');
}
template<class T> void outp(T* v, int n) {
  REP(i, n) cout << *v++ << (i + 1 == n ? '\n' : ' ');
}

const int h = 100011;
int n, k;
char s[2][h];
int d[2][h];
vi q;

void go(int u, int i, int l) {
  if(i>=n) {
    printf("YES\n");
    exit(0);
  }
  if(i<l || s[u][i]=='X') return;
  if(d[u][i]==-1) {
    d[u][i] = l;
    q.pb(i+u*n);
  }
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  REP(u, 2) scanf("%s", s[u]);

  CL(d, -1);
  d[0][0] = 0;
  q.pb(0);
  int a = 0;
  while(a < sz(q)) {
    int v = q[a++];
    int u = 0;
    //printf("%d %d: %d\n", u, v, d[u][v]);
    if(v>=n) {
      u = 1;
      v -= n;
    }
    go(u, v-1, d[u][v]+1);
    go(u, v+1, d[u][v]+1);
    go(1-u, v-k, d[u][v]+1);
    go(1-u, v+k, d[u][v]+1);
  }
  printf("NO\n");

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
}