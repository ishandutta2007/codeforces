#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
  
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, M, K; ll G, L;

// rossetta code

// returns x where (a * x) % b == 1
ll mul_inv(ll a, ll b)
{
    ll b0 = b, t, q;
    ll x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}
 
ll chinese_remainder(vector<ll> n, vector<ll> a)
{
    ll p, i, prod = 1, sum = 0, len = n.size();
 
    for (i = 0; i < len; i++) prod *= n[i];
 
    for (i = 0; i < len; i++) {
        p = prod / n[i];
        sum += a[i] * mul_inv(p, n[i]) * p;
    }
 
    return sum % prod;
}

ll gcd (ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

ll solve (int x, int y) {
    if((y - x) % G != 0) return (ll)1e18;
    return chinese_remainder({N / G, M / G}, {x / G, y / G}) * G + x % G;
}

int main() {
 scanf("%d%d%d", &N, &M, &K);
 N *= 2; M *= 2;
 G = gcd(N, M); L = N / G * M;

 for(int i = 1; i <= K; i++) {
    int x, y; scanf("%d%d", &x, &y);
    ll cand[] = {
        solve(x, y),
        solve(N-x, y),
        solve(x, M-y),
        solve(N-x, M-y)
    };
    ll ans = *min_element(cand, cand+4);
    printf("%lld\n", ans == (ll)1e18 ? -1 : ans);
 }
 return 0;
}