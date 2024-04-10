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

const int h = 1111;
pii fr[h],to[h];
int n,p;

struct A
{
  int a,b, d;
  A(int a=0, int b=0, int d=0) : a(a), b(b), d(d) {};
  void outp() { printf("%d %d %d\n", a, b, d); }
};
vector<A> ans;

int main () {
  #ifdef LocalHost
  freopen("input.txt", "r", stdin);
  #endif
  scanf("%d%d", &n, &p);
  int a,b,d;
  REP(i, p)
  {
    scanf("%d%d%d", &a, &b, &d);
    fr[a] = pii(b, d);
    to[b] = pii(a, d);
  }
  FOR(i, 1, n+1) if(to[i].X==0)
  {
     int j = i, d = INF;
     while(fr[j].X!=0)
     {
       d = min(d, fr[j].Y);
       j = fr[j].X;
     }
     if(i!=j) ans.pb( A(i, j, d) );
  }
  printf("%d\n", sz(ans));
  REP(i, sz(ans)) ans[i].outp();
  return 0;
}