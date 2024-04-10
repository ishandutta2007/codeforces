#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i(a),_b(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a),_b(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INFLL = 1000000000000000000LL;

int n,m, s,f,t, p;

int ff (int f, int t) {
  int k = (t-f+p-1) / p;
  int res = p*k + f;
  if(0<f && f<m-1) {
    k = k*p - f;
    if(k>=t) res = min(res, k);
  }
  return res;
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  p = 2*m-2;
  REP(i, n) {
    scanf("%d%d%d", &s, &f, &t);
    if(s==f) printf("%d\n", t);
    else {
      --s; --f;
      int r = ff(s, t);
//      printf("%d\n", r);
      printf("%d\n", ff(f, r));
//      printf("\n");
    }
  }
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}