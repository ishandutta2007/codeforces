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

const int h = 2002;
int n, ans;
int p[h];

int main () {
#ifdef LocalHost
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  scanf("%d", &n);
  REP(i, n) scanf("%d", p+i);
  REP(i, n) if(p[i]!=-1) --p[i];
  ans = 0;
  REP(i, n) {
    int j = i, l = 1;
    while(p[j]!=-1) ++l, j = p[j];
    ans = max(ans, l);
  }
  printf("%d\n", ans);
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}