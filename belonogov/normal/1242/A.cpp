#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


int main() {
#define TASK "A"
#ifdef HOME
  assert(freopen(TASK".in", "r", stdin));
#endif
  ll n;
  scanf("%lld", &n);
  ll init_n = n;
  vector<ll> div;
  for (ll i = 2; i * i <= n; i++) {
    for (;n % i == 0; n /= i) {
      div.pb(i);
    }
  }
  if (n > 1) {
    div.pb(n);
  }
  n = init_n;
  if (div.size() <= 1) {
    cout << n << endl;
    return 0;
  }
  bool flag = 1;
  for (auto x: div) {
    flag &= x == div[0];
  }
  if (flag) {
    cout << div[0] << endl;
  }
  else {
    cout << 1 << endl;
  }








  return 0;
}