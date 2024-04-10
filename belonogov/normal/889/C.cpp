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
const int MOD = 1e9 + 7;


ll rev(ll a, ll m) {
    if (a == 0) return 0;
    return ((1 - rev(m % a, a) * m) / a + m) % m;
}


int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, k;   
    scanf("%d%d", &n, &k);
    vector<ll> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<ll> rfact(n + 1);
    rfact[n] = rev(fact[n], MOD);
    assert(fact[n] * rfact[n] % MOD == 1);

    for (int i = n - 1; i >= 0; i--) {
        rfact[i] = (rfact[i + 1] * (i + 1)) % MOD;
    }

    auto getC = [&](int nn, int kk) {
        assert(0 <= kk && kk <= nn);
        return fact[nn] * rfact[kk] % MOD * rfact[nn - kk] % MOD;
    };


    vector<ll> f(n + 1);
    vector<ll> g(n + 1);
    vector<ll> prefG(n + 1);
    f[1] = 1;
    g[1] = 1;
    prefG[1] = 1;

    for (int i = 2; i <= n; i++) {
        ll tmp = prefG[i - 1];   
        if (i - k - 1 >= 1) {
            tmp = (tmp - prefG[i - k - 1] + MOD) % MOD;
        }
        tmp = (tmp * fact[i - 2]) % MOD;
        f[i] = tmp;
        g[i] = f[i] * rfact[i - 1] % MOD;
        prefG[i] = (prefG[i - 1] +  g[i]) % MOD;
    }

    ll answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = (answer + getC(n - 1, i - 1) * f[i] % MOD * fact[n - i]) % MOD;
        //db(answer);
    }
    //for (int i = 1; i <= n; i++) {
        //db2(f[i], i);
    //}
    cout << (fact[n] - answer + MOD) % MOD << endl;




    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}