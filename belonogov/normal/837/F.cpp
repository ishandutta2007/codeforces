#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;
const ll INF18 = 1.1e18;



ll calc(ll n, ll k) {
    assert(k < 10);
    ll f = 1;
    for (int i = 0; i < k; i++) {
        ll mul = n - i;
        ll dv = (i + 1);
        ll g = __gcd(dv, mul);
        dv /= g;
        mul /= g;
        assert(f % dv == 0);
        f /= dv;
        if (f * 1.0 * mul > INF18) {
            return INF18;
        }
        f *= mul;
    }
    return f;
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    vector<ll> a(n);
    int cur = -1; 
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] != 0 && cur == -1) {
            cur = i;
        }
        if (a[i] >= k) {
            puts("0");
            return 0;
        }
    }
    a.erase(a.begin(), a.begin() + cur);     
    n = a.size();
    if (n > 10) {
        for (int answer = 0; ; answer++) {
            for (int i = 0; i < n; i++) {
                if (a[i] >= k) {
                    cout << answer << endl;
                    return 0;
                }
                if (i != 0) {
                    a[i] += a[i - 1];
                }
            }
        }
    }
    ll l = 0;
    ll r = INF18;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        bool win = 0;
        ll sum = 0; 
        //mid = 2;
        for (int i = 0; i < n; i++) {
            ll f = calc(mid + i - 1, i);
            //db2(f, a[n - 1 - i]);
            if (f * 1.0 * a[n - 1 - i] > INF18) {
                win = 1;
                break;
            }
            sum += f * a[n - 1 - i];
        }
        if (sum >= k) {
            win = 1;
        }
        //db(win);
        //exit(0);
        if (win) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << endl;

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}