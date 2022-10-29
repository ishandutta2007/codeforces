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

vi l;
int pl,pr, vl,vr, k;

inline ll inter (int a1, int b1, int a2, int b2) {
  return max(0, min(b1, b2) - max(a1, a2) + 1);
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  l.clear();
  FOR(d, 1, 10) REP(u, 1<<d) {
    int v = 0;
    FORD(i, d-1, 0) {
      v *= 10;
      if(u&1<<i) v+=7;
      else v+=4;
    }
    l.pb(v);
  }
  //REP(i, sz(l)) printf("%d\n", l[i]);
  scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &k);
  ll res = 0;
  for(int i=0; i+k<=sz(l); ++i) {
    res += inter(i==0 ? 1 : l[i-1]+1, l[i], pl, pr) * inter(l[i+k-1], i+k==sz(l) ? INF : l[i+k]-1, vl, vr);
    res += inter(i==0 ? 1 : l[i-1]+1, l[i], vl, vr) * inter(l[i+k-1], i+k==sz(l) ? INF : l[i+k]-1, pl, pr);
    if(k==1 && pl<=l[i] && l[i]<=pr && vl<=l[i] && l[i]<=vr) res -= 1;
  }
  printf("%.9lf\n", double(res) / double(pr-pl+1) / double(vr-vl+1));
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}