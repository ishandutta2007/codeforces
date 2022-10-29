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
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  ll x, y;
  cin >> x >> y;
  if (__gcd(x, y) > 1) {
    cout << "Impossible\n";
    return 0;
  }
  vector<pair<ll, char>> v;
  while (x > 1 || y > 1) {
    if (x > y) v.eb(x/y, 'A'), x %= y;
    else v.eb(y/x, 'B'), y %= x;
  }
//  reverse(all(v));
//  --v[0].X;
  --v.back().X;
  for (auto& t : v) cout << t.X << t.Y;
  cout << endl;

//  pii a = {1, 0}, b = {0, 1};
//  for (auto& t : v) {
//    if (t.Y == 'A') b.X += t.X * a.X, b.Y += t.X * a.Y;
//    else a.X += t.X * b.X, a.Y += t.X * b.Y;
//  }
//  cout << a.X + b.X << ' ' << a.Y + b.Y << endl;

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}