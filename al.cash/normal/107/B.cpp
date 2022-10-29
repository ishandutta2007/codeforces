#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <functional>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i(a), _b(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a), _b(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1111;
int n,m,h, s[N];

int main () {
  #ifdef LocalHost
  freopen("input.txt", "r", stdin);
  #endif
  scanf("%d%d%d", &n, &m, &h);
  --h;
  REP(i, m) scanf("%d", s+i);
  int sum = 0;
  REP(i, m) sum += s[i];
  if(sum<n)
  {
    printf("-1\n");
    return 0;
  }
  if(sum-s[h]<n-1) printf("1.0\n");
  else
  {
    double res = 1;
    REP(i, n-1) res *= double(sum-s[h]-n+i+2) / double(sum-n+i+1);
    printf("%.9lf\n", 1 - res);
  }
  return 0;
}