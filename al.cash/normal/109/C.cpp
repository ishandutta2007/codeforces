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
int n;

vi r[h];

bool lucky (int v) {
  while(v) {
    int r = v%10;
    if(r!=4 && r!=7) return false;
    v /= 10;
  }
  return true;
}

bool us[h];
int q[h];

ll ans = 0;

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  scanf("%d", &n);
  int a,b, w;
  REP(i, n-1) {
    scanf("%d%d%d", &a, &b, &w);
    --a; --b;
    if(!lucky(w)) {
      r[a].pb(b);
      r[b].pb(a);
    }
  }
  a = b = 0;
  REP(i, n) if(!us[i]) {
    int k = 1;
    q[b++] = i;
    us[i] = 1;
    while(a<b) {
      int v = q[a++];
      REP(j, sz(r[v])) {
        int u = r[v][j];
        if(!us[u]) {
          us[u] = 1;
          q[b++] = u;
          ++k;
        }
      }
    }
    ans += k * ll(n-k) * ll(n-k-1);
  }
  cout << ans << endl;
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}