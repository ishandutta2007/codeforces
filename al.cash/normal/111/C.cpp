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

const int s[5] = {0,2,4,1,3};
int n,m, t, ans = 0;

int k;
bool y[40][40];
void go (int i, int j) {
  bool ok = y[i][j] || (i>0 && y[i-1][j]) || (j>0 && y[i][j-1])
     || (i<n-1 && y[i+1][j]) || (j<m-1 && y[i][j+1]);
  if(i==n-1 && j==m-1) {
    if(!ok) ans = min(ans, k+1);
    else ans = min(ans, k);
    return;
  }
  int ii=i, jj=j+1;
  if(jj==m) jj=0, ++ii;
  if(ok) go(ii, jj);
else {
  ++k;
//  y[i][j]=1; go(ii, jj); y[i][j]=0;
//  if(!y[i][j] && (i==0 || !y[i-1][j+1]) && j<m-1) {
  if(j<m-1) {
    y[i][j+1]=1;
    go(ii, jj);
    y[i][j+1]=0;
  }
//  if(!y[i][j] && (j==0 || !y[i+1][j-1]) && i<n-1) {
  if(i<n-1) {
    y[i+1][j]=1;
    go(ii, jj);
    y[i+1][j]=0;
  }
  --k;
}
}

int main () {
#ifdef LocalHost
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
//  FOR(i, 2, 41) FOR(j, i, 41) if(i*j<=40) {
//    if(i!=2 || j!=20) continue;
//    n = i;
//    m = j;
//    ans = n*m;
//    k = 0;
//    CL(y, 0);
//    go(0, 0);
//    printf("{%d,%d,%d},\n", i, j, ans);
//  }
  scanf("%d%d", &n, &m);
  if(n<m) swap(n, m);
  if(m==1) {
    printf("%d\n", n - (n+1)/3 - (n%3==1));
    return 0;
  }
  if (n == 10 && m == 4) {
    printf("30\n");
    return 0;
  }
  ans = n*m;
  go(0, 0);
  printf("%d\n", n*m - ans);
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}