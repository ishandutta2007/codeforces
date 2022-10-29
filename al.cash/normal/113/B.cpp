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
#define FOR(i, a, b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a), _b(b); i >= _b; --i)
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

const int h = 2002;
string t, b,e;
int l[h][h];
int u[h][h];
bool c[h][h];

bool y[h];

int main () {
#ifdef LocalHost
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
  cin>>t>>b>>e;
  int n = sz(t);
  FORD(i, n-1, 0) FORD(j, n-1, 0)
    l[i][j] = (t[i]==t[j]) ? l[i+1][j+1]+1 : 0;
  //REP(i, n) { REP(j, n) printf("%d ", l[i][j]); printf("\n"); }
  REP(i, n) REP(k, n+1) u[i][k] = i;
  REP(i, n) FORD(j, i-1, 0) u[i][l[i][j]] = j;
  REP(i, n) FORD(k, n-1, 0) u[i][k] = min(u[i][k], u[i][k+1]);
  //REP(i, n) { REP(j, n+1) printf("%d ", u[i][j]); printf("\n"); }
  REP(i, n) y[i] = (t.substr(i, sz(b)) == b);
  CL(c, 0);
  int res = 0;
  REP(i, n) {
    if(t.substr(i, sz(e)) == e) {
      REP(j, i+1-max(0, sz(b)-sz(e))) if(y[j]) {
        int d = i-j+sz(e);
        if(!c[u[j][d]][d]) ++res;
        c[u[j][d]][d] = true;
      }
    }
  }
  printf("%d\n", res);
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}