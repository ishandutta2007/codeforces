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

const int h = 5005;
int n;
char c[h][h];
bool a[h][h];
int u[h], p[h];

vi ans;
void dfs (int v, int r) {
  u[v] = r;
  REP(i, n) if(a[v][i]) {
    if(u[i]==-1) p[i]=v, dfs(i, r);
    else if(u[i]==r) {
      vi t;
      t.pb(v);
      while(v!=i) v=p[v], t.pb(v);
      int j = 1;
      while(j<sz(t)-2 && a[t[j]][t.back()]) ++j;
      if(j>=sz(t)-2) {
        REP(u, 3) ans.pb(t[sz(t)-u-1]);
      }
      else {
        ans.pb(t.back());
        ans.pb(t[j]);
        ans.pb(t[j-1]);
      }
      REP(u, 3) printf("%d ", ans[u]+1);
      printf("\n");
      exit(0);
    }
  }
  u[v] = n;
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  scanf("%d", &n);
  REP(i, n) scanf("%s", c+i);
  REP(i, n) REP(j, n) a[i][j] = c[i][j]=='1';
  CL(u, -1);
  REP(i, n) if(u[i]==-1) p[i]=-1, dfs(i, i);
  printf("-1\n");
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}