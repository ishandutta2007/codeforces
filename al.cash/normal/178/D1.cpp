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

int main() {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  m = n*n;
  REP(i, m) {
    scanf("%d", a+i);
    s += a[i];
  }
  s /= n;
  printf("%d\n", s);

  if(n==1) {
    printf("%d\n", a[0]);
  }
  if(n==2) {
    sort(a, a+m);
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
    sort(a, a+m);
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

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}