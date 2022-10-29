#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
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

template <class T> T& smin(T& x, const T& y) { if (x > y) x = y; return x; }
template <class T> T& smax(T& x, const T& y) { if (x < y) x = y; return x; }
template <class T> T sqr(const T& x) { return x * x; }

template <typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

template <class C, int N>
class KMP {
public:
  const C* pattern;
  int n, prefixF[N+1];

  void build(const C* s, int newn) {
    pattern = s;
    n = newn;
    prefixF[0] = prefixF[1] = 0;
    for (int i = 1; i < n; ++i) {
      int j = prefixF[i];
      while (j > 0 && pattern[i] != pattern[j]) j = prefixF[j];
      prefixF[i+1] = j + (pattern[i] == pattern[j]);
    }
  }
};

const int N = 2e6+6;
int n;
char a[N];

void rev(char& c) {
  switch (c) {
    case 'E': c = 'W'; break;
    case 'W': c = 'E'; break;
    case 'N': c = 'S'; break;
    case 'S': c = 'N'; break;
  }
}

KMP<char, N> kmp;

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%s", &n, a);
  --n;
  scanf("%s", a+n);
  reverse(a, a+n);
  REP(i, n) rev(a[i]);
  kmp.build(a, 2*n);
  printf("%s\n", kmp.prefixF[2*n] == 0 ? "YES" : "NO");

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}