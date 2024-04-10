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

const int h = 4;

int n, m, s;
int a[h*h];

bool ok(int i0, int i1) {
  return a[i0] + a[i1] == s;
}

bool ok(int i0, int i1, int i2) {
  return a[i0] + a[i1] + a[i2] == s;
}

int r[h][h];

void go7(int u) {
  int l = -INF;
  int b[3], f[3];
  REP(i, m) if(a[i]!=l && (u&1<<i)) {
    r[2][2] = a[i];
    int v = u - (1<<i);
    f[0] = r[2][3] = s - r[2][0] - r[2][1] - r[2][2];
    f[1] = r[3][2] = s - r[0][2] - r[1][2] - r[2][2];
    f[2] = r[3][3] = s - r[0][0] - r[1][1] - r[2][2];
    int k = 0;
    REP(j, m) if(v&1<<j) b[k++] = a[j];
    sort(b, b+3);
    sort(f, f+3);
    if(b[0]==f[0] && b[1]==f[1] && b[2]==f[2]) {
      REP(ii, 4) {
        REP(jj, 4) printf("%d ", r[ii][jj]);
        printf("\n");
      }
      exit(0);
    }
    l = a[i];
  }
}

void go6(int u) {
  int l = -INF;
  REP(i, m) if(a[i]!=l && (u&1<<i)) {
    r[1][1] = a[i];
    int v = u - (1<<i);
    int f = r[1][3] = s - r[1][0] - r[1][1] - r[1][2];
    int j = 0;
    while(j<m && a[j]<f) ++j;
    while(j<m && (~v&1<<j)) ++j;
    if(j<m && a[j]==f) {
      v -= 1<<j;
      f = r[3][1] = s - r[0][1] - r[1][1] - r[2][1];
      j = 0;
      while(j<m && a[j]<f) ++j;
      while(j<m && (~v&1<<j)) ++j;
      if(j<m && a[j]==f) go7(v - (1<<j));
    }
    l = a[i];
  }
}

void go5(int u) {
  int l = -INF;
  REP(i, m) if(a[i]!=l && (u&1<<i)) {
    r[1][2] = a[i];
    int v = u - (1<<i);
    int f = r[2][1] = s - r[0][3] - r[1][2] - r[3][0];
    int j = 0;
    while(j<m && a[j]<f) ++j;
    while(j<m && (~v&1<<j)) ++j;
    if(j<m && a[j]==f) go6(v - (1<<j));
    l = a[i];
  }
}

void go4(int u) {
  int l = -INF;
  REP(i, m) if(a[i]!=l && (u&1<<i)) {
    r[2][0] = a[i];
    int v = u - (1<<i);
    int f = r[3][0] = s - r[0][0] - r[1][0] - r[2][0];
    int j = 0;
    while(j<m && a[j]<f) ++j;
    while(j<m && (~v&1<<j)) ++j;
    if(j<m && a[j]==f) go5(v - (1<<j));
    l = a[i];
  }
}

void go3(int u) {
  int l = -INF;
  REP(i, m) if(a[i]!=l && (u&1<<i)) {
    r[1][0] = a[i];
    go4(u - (1<<i));
    l = a[i];
  }
}

void go2(int u) {
  int l = -INF;
  REP(i, m) if(a[i]!=l && (u&1<<i)) {
    r[0][2] = a[i];
    int v = u - (1<<i);
    int f = r[0][3] = s - r[0][0] - r[0][1] - r[0][2];
    int j = 0;
    while(j<m && a[j]<f) ++j;
    while(j<m && (~v&1<<j)) ++j;
    if(j<m && a[j]==f) go3(v - (1<<j));
    l = a[i];
  }
}

void go1(int u) {
  int l = -INF;
  REP(i, m) if(a[i]!=l && (u&1<<i)) {
    r[0][1] = a[i];
    go2(u - (1<<i));
    l = a[i];
  }
}

void go0(int u) {
  int l = -INF;
  REP(i, m) if(a[i]!=l && (u&1<<i)) {
    r[0][0] = a[i];
    go1(u - (1<<i));
    l = a[i];
  }
}

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  //printf("%I64d\n\n", ll(16)*15*14 * 12*11 * 9 * 7 * 4);

  scanf("%d", &n);
  m = n*n;
  REP(i, m) {
    scanf("%d", a+i);
    s += a[i];
  }
  s /= n;
  printf("%d\n", s);

  sort(a, a+m);

  if(n==1) {
    printf("%d\n", a[0]);
  }
  if(n==2) {
    do {
      if(ok(0, 1) && ok(0, 2) && ok(0, 3) && ok(1, 2)) {
        REP(i, 2) {
          REP(j, 2) printf("%d ", a[i*2+j]);
          printf("\n");
        }
        break;
      }
    } while(next_permutation(a, a+m));
  }
  if(n==3) {
    do {
      if(ok(0, 1, 2) && ok(3, 4, 5) && ok(0, 3, 6) && ok(1, 4, 7) &&
          ok(0, 4, 8) && ok(2, 4, 6)) {
        REP(i, 3) {
          REP(j, 3) printf("%d ", a[i*3+j]);
          printf("\n");
        }
        break;
      }
    } while(next_permutation(a, a+m));
  }
  if(n==4) {
    go0((1<<m)-1);
  }

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}