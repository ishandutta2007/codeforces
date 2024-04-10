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

const int h = 16;
bool us[h];
int n,m, l[h], res[h];
ll y, d[1<<h];

ll calc ()
{
  CL(d, 0);
  d[0] = 1;
  REP(u, 1<<n) if(d[u]>0)
  {
    int k = 0;
    REP(i, n) if(u&1<<i) ++k;
    //printf("%d %d: %d!\n", u, k, d[u]);
    REP(j, n) if(~u&1<<j)
      if((res[j]==-1 || res[j]==k) && (u&l[j])==l[j])
        d[u|1<<j] += d[u];
  }
  return d[(1<<n)-1];
}

int main () {
  #ifdef LocalHost
  freopen("input.txt", "r", stdin);
  #endif
  cin>>n>>y>>m;
  y -= 2001;
  int a,b;
  REP(i, m)
  {
    scanf("%d%d", &a, &b);
    l[b-1] |= 1<<(a-1);
  }
  //REP(i, n) printf("%d\n", l[i]);
  CL(res, -1);
  CL(us, 0);
  REP(i, n) REP(j, n+1) if(!us[j])
  {
    if(j==n)
    {
      printf("The times have changed\n");
      return 0;
    }
    res[i] = j;
    ll r = calc();
    //printf("%d %d: %lld\n", i, j, r);
    if(r>y)
    {
      us[j] = true;
      break;
    }
    else
      y -= r;
  }
  REP(i, n) printf("%d ", res[i]+1);
  printf("\n");
  return 0;
}