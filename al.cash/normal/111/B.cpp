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

const int h = 100011;
int x,y, res, l[h];

void ch (int d, int i) {
  if(l[d]<i-y) ++res;
  l[d] = i;
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  REP(i, h) l[i] = -INF;
  int t;
  scanf("%d", &t);
  REP(it, t) {
    scanf("%d%d", &x, &y);
    res = 0;
    for(int i=1; i*i<=x; ++i) if(x%i==0) {
      ch(i, it);
      if(i*i!=x) ch(x/i, it);
    }
    printf("%d\n", res);
  }
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}