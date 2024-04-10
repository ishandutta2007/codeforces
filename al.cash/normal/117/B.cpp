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

int a,b, mod;

int main () {
#ifdef LocalHost
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d%d", &a, &b, &mod);
  int i = 0, r = 0;
  int v = INF % mod;
  while(i<=a && (r == 0 || r+b >= mod)) {
    ++i;
    r += v;
    if(r>=mod) r-=mod;
    if(r==0) {
      i = a+1;
      break;
    }
  }
  if(i<=a) printf("1 %09d\n", i);
  else printf("2\n");
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}