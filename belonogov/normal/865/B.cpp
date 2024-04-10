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
const int INF = 1.01e9;
typedef vector<int> vi;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, s;
    scanf("%d%d", &n, &s);
    vector<int> w(n);
    vector<int> a(n);
    vector<int> b(n);
    ll sumW = 0;
    ll aMore = 0;
    forn(i, n) {
        scanf("%d%d%d", &w[i], &a[i], &b[i]);
        sumW += w[i];
        if (a[i] > b[i]) {
            aMore += w[i];
        }
    }

    ll cnt = (sumW + s - 1) / s;
    ll answer = 0;

    auto check = [&](ll cntA) {
        ll res = 0; 
        vector<pair<ll,ll>> d;
        forn(i, n) {
            res += w[i] * 1ll * a[i];
            d.pb({b[i] - a[i], w[i]});
        }
        sort(all(d), [](pair<ll,ll> A, pair<ll,ll> B) {
                return abs(A.F) > abs(B.F);
                });
        ll canB = (cnt - cntA) * s;
        ll canA = cntA * s;
        for (auto x: d) {
            for (;x.S > 0;) {
                if (x.F >= 0 && canB > 0) {
                    ll Q = min(x.S, canB); 
                    canB -= Q;
                    x.S -= Q;
                    res += x.F * Q;
                }
                else if (x.F <= 0 && canA > 0) {
                    ll Q = min(x.S, canA); 
                    canA -= Q;
                    x.S -= Q;
                }
                else if (x.F >= 0) {
                    assert(canA >= x.S);
                    canA -= x.S;
                    x.S = 0;
                }
                else if (x.F <= 0) {
                    assert(canB >= x.S);
                    res += x.S * 1ll * x.F;
                    canB -= x.S;
                    x.S = 0;
                }
            }
        }
        answer = max(answer, res);
    };
    ll f = aMore / s;
    check(f);
    if (f + 1 <= cnt)
        check(f + 1);
    cout << answer << endl;
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}