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

const int h = 100011;

int n,k, p=0;
char s[h];

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d%s", &n, &k, s);
  p = 0;
  REP(i, k) {
    while(p<n-1 && (s[p]!='4' || s[p+1]!='7')) ++p;
    if(p==n-1) break;
    if(!(p&1) && p+2<n && s[p+2]=='7') {
      if((k-i)&1) s[p+1] = '4';
      break;
    }
    if((p&1) && p>0 && s[p-1]=='4') {
      if((k-i)&1) s[p] = '7';
      break;
    }
    if(p&1) s[p] = '7';
    else s[p+1] = '4';
    --p;
  }
  printf("%s\n", s);
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}