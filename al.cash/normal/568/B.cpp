#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* separator = " ", const char* closing = "\n") {
  for (Iterator it = begin; it != end; printf(fmt, *it),
       printf("%s", ++it == end ? closing : separator));
}


const int mod = 1e9+7;
void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
int add(int x, int y) { inc(x, y); return x; }
int mul(int x, int y) { return (ll(x) * y) % mod; }

void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }
int sub(int x, int y) { dec(x, y); return x; }

template<class T> T qpow(T a, int p) {
  T res = 1;
  for (; p; p >>= 1, a = mul(a, a))
    if (p & 1) res = mul(res, a);
  return res;
}

template<size_t N, size_t M, class T>
void calcCnm(T (&C)[N][M]) {
  C[0][0] = 1;
  FOR(j, 1, M) C[0][j] = 0;
  FOR(i, 1, N) {
    C[i][0] = 1;
    FOR(j, 1, M) C[i][j] = add(C[i-1][j-1], C[i-1][j]);
  }
}

const int N = 4004;
int C[N][N], d[N][2];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  
  calcCnm<N, N>(C);
  
  int n;
  scanf("%d", &n);
  d[0][0] = 1;
  FOR(i, 1, n+1) {
    d[i][0] = 0;
    d[i][1] = add(d[i-1][0], d[i-1][1]);
    REP(j, i) {
      inc(d[i][0], mul(C[i-1][j], d[i-j-1][0]));
      inc(d[i][1], mul(C[i-1][j], d[i-j-1][1]));
    }
  }
  printf("%d\n", d[n][1]);
  
#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}