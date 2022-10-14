#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <memory.h>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
const double eps = 1e-12;
const int INF = 1<<30;
const LL LINF = 1ll<<61;

#define pb push_back
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define CLR(a, v) memset((a),(v),sizeof(a))
#define sqr(a) ((a)*(a))
const int BUFFER_SZ = 1<<20;
const int MOD = 1000*1000*1000+7;

char BUFFER[BUFFER_SZ];
int gi() { int x; scanf("%d", &x); return x; }
double gd() { double x; scanf("%lf", &x); return x; }
LL gll() { LL x; scanf("%lld", &x); return x; }
VI gvi(int n) { VI a; while(n-->0) a.pb(gi()); return a;}
string gs() { scanf("%s", BUFFER); return string(BUFFER); }
template <class T> void print(vector<T> &x, string format) { format += "%c";for (int i = 0; i < x.size(); ++i) printf(format.c_str(), x[i], i+1==x.size() ? '\n' : ' '); }
// ---------------------------------------------------------- //


void solve() {
  int n = gi();
  VI a = gvi(n);
  for (int i = 0; i < a.size(); ++i) {
    for (int j = i+1; j <a.size(); ++j) {
      for (int k = j+1; k < a.size(); ++k) {
        if (a[i]==a[j]+a[k]) {
          printf("%d %d %d\n", i+1, j+1, k+1);
          return;
        }
        if (a[j]==a[i]+a[k]) {
          printf("%d %d %d\n", j+1, i+1, k+1);
          return;
        }
        if (a[k]==a[i]+a[j]) {
          printf("%d %d %d\n", k+1, i+1, j+1);
          return;
        }
      }
    }
  }
  printf("-1\n");
}

int main() {
#ifdef DEAD_RABBIT
  freopen("../in.txt","r",stdin);
  clock_t start = clock();
#endif
  solve();
#ifdef DEAD_RABBIT
  fprintf(stdout, "Time: %.3lf\n", 1.0*(clock()-start)/CLOCKS_PER_SEC);
#endif
  return 0;
}