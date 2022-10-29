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

const int h = 500005, mod = 1000003;
int m, n, g0,g1, v0,v1;
int a[h];

void inc (int &a, int b) { a+=b; if(a>=mod) a-=mod; }

int main () {
#ifdef LocalHost
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  char c;
  REP(u, n*m) {
    c = 0;
    while(!isdigit(c) && c!='.') scanf("%c", &c);
    if(isdigit(c)) a[u] = c-'1';
    else a[u] = -1;
  }
  int ans = 1;
  REP(j, m) {
    v0 = v1 = 0;
    REP(i, n) {
      int u = i*m + j;
      if((i+j)%2==0) {
        if(a[u]==0 || a[u]==3) v0 |= 1;
        else if(a[u]!=-1) v0 |= 2;
      }
      else {
        if(a[u]==0 || a[u]==3) v1 |= 1;
        else if(a[u]!=-1) v1 |= 2;
      }
    }
    if((v0&v1)!=0 || v0==3 || v1==3) ans = 0;
    if((v0|v1)==0) inc(ans, ans);
  }
  REP(i, n) {
    g0 = g1 = 0;
    REP(j, m) {
      int u = i*m + j;
      if((i+j)%2==0) {
        if(a[u]==0 || a[u]==1) g0 |= 1;
        else if(a[u]!=-1) g0 |= 2;
      }
      else {
        if(a[u]==0 || a[u]==1) g1 |= 1;
        else if(a[u]!=-1) g1 |= 2;
      }
    }
    if((g0&g1)!=0 || g0==3 || g1==3) ans = 0;
    if((g0|g1)==0) inc(ans, ans);
  }
  printf("%d\n", ans);
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}