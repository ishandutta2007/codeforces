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

const double pi = 2*acos(0.0);

const int h = 2002;
const int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

int n, cik, sqk;
bool a[h][h];

vector<pii> q;

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
#ifdef LocalHost
  freopen("medium_2.in", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  int c;
  REP(i, n) REP(j, n) {
    scanf("%d", &c);
    a[i][j] = c;
  }
  REP(i, n) REP(j, n) if(a[i][j]) {
    q.clear();
    q.pb(pii(i, j));
    a[i][j] = 0;
    int c = 0;
    while(c < sz(q)) {
      pii u = q[c++];
      REP(d, 4) {
        int ii = u.X + dx[d];
        int jj = u.Y + dy[d];
        if(a[ii][jj]) {
          q.pb(pii(ii, jj));
          a[ii][jj] = 0;
        }
      }
    }
    int k = sz(q);
    double x = 0, y = 0;
    REP(i, k) x += q[i].X, y += q[i].Y;
    x /= k;
    y /= k;
    double r = 0;
    REP(i, k) r = max(r, dist(x, y, q[i].X, q[i].Y));
    if(fabs(1 - pi*r*r / k) < 0.1) ++cik;
    else ++sqk;
  }

  printf("%d %d\n", cik, sqk);

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}