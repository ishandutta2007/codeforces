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

vector<ll> a;

int l, r;
ll ans;

int main () {
#ifdef LocalHost
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  a.pb(0);
  FOR(k, 1, 10) REP(u, 1<<k) {
    int v = 0;
    REP(i, k) {
      v *= 10;
      if(u&1<<(k-i-1)) v += 7;
      else v += 4;
    }
    a.pb(v);
  }
  a.pb(4444444444LL);
//  REP(i, 20) printf("%d ", a[i]); printf("\n");
  scanf("%d%d", &l, &r);
  --l;
  ans = 0;
  FOR(i, 1, sz(a)) {
    if(r<=a[i]) {
      ans += a[i] * (r - max(a[i-1], (ll)l));
      break;
    }
    if(l<a[i]) ans += a[i] * (a[i] - max(a[i-1], (ll)l));
  }
  cout << ans << endl;
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}