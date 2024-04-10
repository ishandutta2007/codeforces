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
const int N = 2111;
const int INF = 1.01e9;
typedef vector<int> vi;
const int MOD = 1e9 + 7;

ll dp[N][N];


ll rev(ll a, ll m) {
    if (a == 0) return 0;
    return ((1 - rev(m % a, a) * m) / a + m) % m;
}

void add(ll& a, ll b) {
    a = (a + b) % MOD;
}

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    //db((47 * rev(47, MOD)) % MOD);
    int n, pa, pb; 
    cin >> n >> pa >> pb;
    dp[1][0] = 1;    
    ll ga = pa * rev(pa + pb, MOD) % MOD;
    ll gb = pb * rev(pa + pb, MOD) % MOD;
    vector<ll> deg(n + 2);
    deg[0] = 1;
    for (int i = 1; i < sz(deg); i++) {
        deg[i] = deg[i - 1] * ga % MOD;
    }
    //db2(ga, gb);
    ll revGA = rev(((1 - ga) + MOD) % MOD, MOD);
    
    ll answer = 0;

    auto go = [&](ll me, int ca, int t, bool flag = 0) {
        if (me == 0) return;
        //db3("GO", me * 1000 % MOD, ca);
        //db2(ca, t);
        int d = n - t;
        if (d > 0) {
            ll F = revGA * revGA % MOD; 
            if (ca >= d) {
                int f = ca - d;
                answer = (answer + gb * (f - 1) % MOD * revGA % MOD * me) % MOD;
                answer = (answer + gb * F % MOD * me) % MOD; 
            }
            else {
                ll com;
                int w = d - ca;
                if (flag) {
                    //db2("ME", w);
                    com = gb * deg[w] % MOD; 
                    //db2(deg[w], gb);
                    //db(com * 625 % MOD);
                }
                else {
                    com = gb * deg[w + 1] % MOD; 
                }
                //db3(F, F * 16% MOD, me);
                answer = (answer + com * F % MOD * me) % MOD;
                //db2(answer, answer * 100 % MOD);
            }
        }
    };

    go(1, 0, 0, 1);
    //db("!!!!!!!!!!!!!!!");
    //db2(answer, answer * 720 % MOD);
    for (int ca = 1; ca <= n; ca++) {
        for (int t = 0; t < n; t++) {
            //db(dp[ca][t] * 1000 % MOD);
            go(dp[ca][t] * gb % MOD, ca, t + ca, 0);
            //db2(ga, gb);
            add(dp[ca + 1][t], dp[ca][t] * ga);
            add(dp[ca][t + ca], dp[ca][t] * gb);
        }
    }
    //db2(answer, n);
    answer = (answer + n) % MOD;

    cout << answer << endl;


    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}