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
const int INF = 1.01e9;
typedef vector<int> vi;
const int MOD = 1e9 + 613;


void fwht(vector<ll>& p, bool inverse) {
    int n = p.size();
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += k * 2) {
            for (int j = 0; j < k; j++) {
                ll v = p[i + j];
                ll u = p[i + j + k];
                if (inverse == 0) {
                    p[i + j] = (v + u) % MOD;
                    p[i + j + k] = v;
                }
                else {
                    p[i + j] = u;
                    p[i + j + k] = (v - u + MOD) % MOD;
                }
            }
        }
    }
}


int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    function<int(int)> getId = [&](int v) {
        return (p[v] == v)? v: p[v] = getId(p[v]);
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'A') {
                int v = getId(i);
                int u = getId(j);
                p[v] = u;
            }
        }
    }
    vector<vector<int>> comp;
    for (int i = 0; i < n; i++) {
        if (p[i] == i) {
            vector<int> who;
            for (int j = 0; j < n; j++) {
                if (getId(j) == i) {
                    who.pb(j);
                } 
            } 
            for (auto v: who) {
                for (auto u: who) {
                    if (s[v][u] == 'X') {
                        puts("-1");
                        return 0;
                    }
                }
            }
            if (who.size() > 1) {
                comp.pb(who);
            }
        }
    }

    int m = comp.size();
    vector<vector<int>> e2(m, vector<int> (m));
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            bool haveXor = 0;
            for (auto v: comp[i]) {
                for (auto u: comp[j]) {
                    haveXor |= s[v][u] == 'X';
                }
            }
            e2[i][j] = haveXor == 0;
            e2[j][i] = haveXor == 0;
        }
    }

    if (m == 0) {
        cout << n - 1 << endl;
        return 0;
    }

    vector<ll> dp(pw(m), -1);
    dp[0] = 1;
    for (int mask = 0; mask < pw(m); mask++) {
        //assert(dp[mask] != -1);
        //dbv(dp);
        if (dp[mask] == -1) {
            dp[mask] = 0;
        }
        if (dp[mask] != 1) continue;
        for (int i = 0; i < m; i++) {
            if ((mask & pw(i)) == 0 && dp[mask | pw(i)] == -1) {
                //db2(mask
                bool ok = 1;
                for (int j = 0; j < m; j++) {
                    if (mask & pw(j)) {
                        ok &= e2[i][j];
                    }
                }
                dp[mask | pw(i)] = ok;
            }
        }  
    }
    //db(m);
    //dbv(dp);

    fwht(dp, 0);
    auto step = dp;
    //db(m);
    //dbv(dp);

    vector<int> megaCof(pw(m));

    function<void(int, int, int)> build = [&](int l, int r, int cof) {
        if (l + 1 == r) {
            megaCof[l] = cof;
            return;
        }
        build(l, (l + r) / 2, cof);
        build((l + r) / 2, r, cof * -1);
    };

    build(0, pw(m), 1);
    //dbv(megaCof);
    int answer = n;
    for (;;answer++) {
        assert(answer <= n * 2);
        //auto tmp = dp;
        //fwht(tmp, 1);
        ll score = 0;  
        for (int i = 0; i < pw(m); i++) {
            score = (score + megaCof[i] * dp[i] + MOD) % MOD;
        }

        if (score != 0) {
            cout << answer << endl; 
            break;
        }
        for (int i = 0; i < pw(m); i++) {
            dp[i] = (dp[i] * step[i]) % MOD;
        }
    }






#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}