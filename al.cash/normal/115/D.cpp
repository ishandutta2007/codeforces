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

const int h = 2002, mod = 1000003;
int add (int a, int b) { a+=b; if(a>=mod) a-=mod; return a; }
int mul (int a, int b) { return ll(a)*b % mod; }

int n;
char s[h];
int d[h][h], c[h];

vi o;

int main () {
#ifdef LocalHost
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  scanf("%s", s);
  n = strlen(s);
  if(s[0]=='*' || s[0]=='/' || !isdigit(s[n-1])) {
//  if(!isdigit(s[n-1])) {
    printf("0\n");
    return 0;
  }
  REP(i, n) {
    if(isdigit(s[i])) {
//      o.pb(0);
      while(i<n && isdigit(s[i])) ++i;
      --i;
      continue;
    }
    if((s[i]=='-' || s[i]=='+') && (i==0 || !isdigit(s[i-1])))
      o.pb(1);
    else {
      if(i!=0 && !isdigit(s[i-1])) {
        printf("0\n");
        return 0;
      }
      o.pb(2);
    }
  }
  n = sz(o);
  //REP(i, n) printf("%d ", o[i]); printf("\n");
  reverse(all(o));
  d[0][0] = 1;
  REP(i, n) {
    c[n] = 0;
    FORD(j, n-1, 0) c[j] = add(c[j+1], d[i][j]);
    if(o[i]==2) {
      REP(j, n) d[i+1][j] = j==0 ? c[j] : c[j-1];
    }
    else {
      REP(j, n) d[i+1][j] = c[j];
    }
  }
  //REP(i, n+1) { REP(j, n) printf("%d ", d[i][j]); printf("\n"); }
  int ans = 0;
  //REP(i, n) ans = add(ans, d[n][i]);
  printf("%d\n", d[n][0]);
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}