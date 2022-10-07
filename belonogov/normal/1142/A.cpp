#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

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
const ll INF18 = 1.01e18;


ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    ll n, k;
    ll a, b;
    cin >> n >> k;
    cin >> a >> b;
    ll mn = INF18;
    ll mx = -INF18;

    for (int cof_a = -1; cof_a <= 1; cof_a += 2) {
        for (int cof_b = -1; cof_b <= 1; cof_b += 2) {
            ll cur_a = (a * cof_a + k) % k;
            ll cur_b = (b * cof_b + k) % k;

            for (ll step = 0; step < n; step++) {
                ll ra = cur_a;
                ll rb = cur_b + step * k;
                ll jump = (rb - ra + n * k) % (n * k);
                ll g = gcd(jump, n * k);
                ll cnt = (n * k) / g;
                mn = min(mn, cnt);
                mx = max(mx, cnt);
            }
        }
    }

    assert(mn <= mx);
    cout << mn << " " << mx << endl;
    return 0;
}