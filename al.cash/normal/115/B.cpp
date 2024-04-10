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

const int h = 155;
int n, m, l;
char s[h][h];

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%s", s+i);
  int l = -1;
  REP(i, n) REP(j, m) if(s[i][j]=='W') l = i;
  int ans = 0, p = 0;
  REP(i, l+1) {
    int u;
    if(i&1) {
      u = 0;
      while(u<p && s[i][u]!='W' && s[i+1][u]!='W') ++u;
      ans += p-u;
    }
    else {
      u = m-1;
      while(u>p && s[i][u]!='W' && s[i+1][u]!='W') --u;
      ans += u-p;
    }
    p = u;
    if(i<l) ++ans;
    //printf("%d: %d\n", i, ans);
  }
  printf("%d\n", ans);
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}