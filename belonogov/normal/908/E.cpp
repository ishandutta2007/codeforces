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
    int n, m;
    cin >> n >> m;
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    map<ll,int> comb;
    for (int i = 0; i < n; i++) {
        //db(i);
        ll mask = 0;
        for (int j = 0; j < m; j++) {
            if (s[j][i] == '1') {
                mask |= pw(j);
            }
        }
        comb[mask]++;
        //comb.insert(mask);
    }
    vector<ll> fact(n + 1);
    vector<ll> rfact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    rfact[n] = rev(fact[n], MOD);
    for (int i = n - 1; i >= 0; i--) {
        rfact[i] = rfact[i + 1] * (i + 1) % MOD;
    }
    //dbv(fact);
    //dbv(rfact);
    auto getC = [&](int nn, int k) {
        assert(0 <= k && k <= nn);
        return fact[nn] * rfact[nn - k] % MOD * rfact[k] % MOD;
    };

    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= i; j++) {
            dp[i] = (dp[i] + getC(i - 1, j - 1) * dp[i - j]) % MOD;
        }
    }
    //dbv(dp);

    //for (auto x: comb) {
        //db2(x.F, x.S);
    //}
    ll answer = 1;
    for (auto x: comb) {
        answer = (answer * dp[x.S]) % MOD;
    }
    cout << answer << endl;



    //ll free = n - comb.size();
    //ll answer = 1;
    ////for (int i = 0; i < free; i++) {
        ////answer = (answer * 2) % MOD;
    ////}
    //db(free);
    //for (int i = 0; i <= n; i++) {
        //db2(i, answer);
        //answer = (answer * 2) % MOD;
    //}


    //cout << answer << endl;


    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}