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
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
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
const ll INF18 = 1e18;


struct Tariff {
    ll a, t, p;
    void read() {
        cin >> a >> t >> p;
    }
};

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    ll f, T, t0;
    cin >> f >> T >> t0;
    vector<Tariff> c(3);
    c[0] = {1, t0, 0};
    c[1].read();
    c[2].read();
    sort(all(c), [](Tariff A, Tariff B) {
            return A.t < B.t || (A.t == B.t && A.p < B.p);
            });
    if (c[0].p == 0) {
        c[1] = c[0];
    }
    if (c[1].p == 0) {
        c[2] = c[1];
    }

    ll answer = INF18;
    //for (auto A: c) {
        //db3(A.a, A.t, A.p);
    //}

    ll cur = f / c[1].a + 1;
    for (ll i = 0; (i - 1) * c[0].a < f; i++) {

        for (;cur > 0;) {
            ll rem = f - (i * c[0].a + (cur - 1) * c[1].a);
            //db3(i, cur, rem);
            if (rem < 0) {
                cur--;
                continue;
            } 
            ll tmr = i * c[0].t * c[0].a + (cur - 1) * c[1].t * c[1].a + rem * c[2].t;
            //db(tmr);

            if (tmr <= T) {
                cur--;
            }
            else {
                break;
            }
            //answer = min(answer, i * c[0].a +  * c[1].a);
        } 
        //i * c[0].a + cur * c[1].a);
        //db2(i, cur);
        //ll rem = f - (i * c[0].a + cur * c[1].a);
        //rem = max(rem, 0ll);
        ll usedA = min(f, i * c[0].a);
        ll usedB = min(f - usedA, cur * c[1].a); 
        ll usedC = f - usedA - usedB;
        ll tmr = usedA * c[0].t + usedB * c[1].t + usedC * c[2].t;
        //db(tmr);
        if (tmr <= T) {
            answer = min(answer, i * c[0].p + cur * c[1].p);
        }
    }

    if (answer == INF18) {
        puts("-1");
    }
    else {
        cout << answer << endl;
    }
    
    
     

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}