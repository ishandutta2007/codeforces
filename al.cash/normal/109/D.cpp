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

bool lucky (int v) {
  while(v) {
    int r = v%10;
    if(r!=4 && r!=7) return false;
    v /= 10;
  }
  return true;
}

int n, a[h], u[h], p[h];
vector<pii> ans;

bool comp (int x, int y) { return a[x] < a[y]; }

void sw (int i, int j) {
  int ui = u[i], uj = u[j];
  swap(p[ui], p[uj]);
  swap(u[i], u[j]);
  ans.pb( pii(i, j) );
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i), p[i] = i;
  bool sorted = true;
  REP(i, n-1) if(a[i]>a[i+1]) {
    sorted = false;
    break;
  }
  if(sorted) {
    printf("0\n");
    return 0;
  }
  int x = 0;
  while(x<n && !lucky(a[x])) ++x;
  if(x==n) {
    printf("-1\n");
    return 0;
  }
  sort(p, p+n, comp);
  REP(i, n) u[p[i]] = i;
  REP(i, n) if(p[i]!=x && p[i]!=i) {
    if(i!=x) sw(i, x);
    x = p[i];
    sw(i, p[i]);
  }
  printf("%d\n", sz(ans));
  REP(i, sz(ans)) printf("%d %d\n", ans[i].X+1, ans[i].Y+1);
//  REP(i, sz(ans)) swap(a[ans[i].X], a[ans[i].Y]);
//  REP(i, n) printf("%d ", a[i]); printf("\n");
//  sorted = true;
//  REP(i, n-1) if(a[i]>a[i+1]) {
//    sorted = false;
//    break;
//  }
//  if(!sorted) while(1);
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}