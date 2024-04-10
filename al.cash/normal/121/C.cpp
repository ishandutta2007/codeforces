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

const int m = 16;
ll f[m];

vector<ll> a;

int n,k,s, ans;

bool islucky(int v) {
  while(v) {
    if(v%10!=4 && v%10!=7) return false;
    v /= 10;
  }
  return true;
}

int main () {
#ifdef LocalHost
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  FOR(k, 1, 10) REP(u, 1<<k) {
    int v = 0;
    REP(i, k) {
      v *= 10;
      if(u&1<<(k-i-1)) v += 7;
      else v += 4;
    }
    a.pb(v);
  }
//  printf("%d\n", sz(a));
  f[0] = 1;
  FOR(i, 1, m) f[i] = f[i-1] * i;

  scanf("%d%d", &n, &k);
  --k;

  if(n<m && f[n]<=k) {
    printf("-1\n");
    return 0;
  }

  ans = 0;
  if(n<m) s=1;
  else s = n-m+2;

  REP(i, sz(a)) if(a[i] < s) ++ans;

  int l = n-s+1;
  vi x;
  REP(i, l) x.pb(s+i);
  REP(i, l) {
    int u = i;
    while(k>=f[l-i-1]) {
      k -= f[l-i-1];
      ++u;
    }
    swap(x[i], x[u]);
    sort(x.begin()+i+1, x.end());
  }
  REP(i, l) if(islucky(s+i) && islucky(x[i])) ++ans;
  printf("%d\n", ans);
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}