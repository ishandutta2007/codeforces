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


ll mul(ll a, ll b, ll mod) {
    ll x = ((long double)a) * b / mod; 
    ll res = a * b - x * mod;
    for (; res < 0; res += mod);
    for (; res >= mod; res -= mod);
    return res;

    /*ll res = 0;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) {
            res = (res + a) % mod;
        }
        a = (a + a) % mod;
    }
    return res;*/
}


ll slowBinPow(ll a, ll b, ll mod) {
    ll res = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) {
            res = mul(res, a, mod);
            //res = (res * a) % mod;
        }
        a = mul(a, a, mod);
        //a = (a * a) % mod;
    }
    return res;

}

ll binPow(ll a, ll b, ll mod) {
    if (a > 2 * INF || true) {
        return slowBinPow(a, b, mod);
    }
    ll res = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
    }
    return res;
}

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
    //freopen("test.txt", "w", stdout);
#endif
    ll n, m, seed, vmax;   
    cin >> n >> m >> seed >> vmax;
    auto rnd = [&]() {
        //db(seed);
        auto ret = seed;
        ll mod = 1e9 + 7;
        seed = (seed * 1ll * 7 + 13) % mod;
        return ret;
    };

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rnd() % vmax + 1;
    }
    int SZ = sqrt(n);
    int CNT = (n + SZ - 1) / SZ;
    vector<ll> blockVal(CNT, -1);
    vector<ll> blockAdd(CNT, 0);
    vector<map<ll,int>> mp(CNT);

    auto rebuildMP = [&](ll id) {
        mp[id].clear();
        ll l = id * SZ;
        ll r = min(n, (id + 1) * SZ); 
        for (int j = l; j < r; j++) {
            mp[id][a[j]]++;
        }
    };

    for (int i = 0; i < CNT; i++) {
        rebuildMP(i);
    }

    auto apply = [&](ll id) {
        if (blockVal[id] != -1) {
            int L = id * SZ;
            int R = min((id + 1) * SZ, n);
            for (int j = L; j < R; j++) {
                a[j] = blockVal[id];
            }
            blockVal[id] = -1;
            assert(blockAdd[id] == 0);
            // todo
        } 
        if (blockAdd[id] != 0) {
            int L = id * SZ;
            int R = min((id + 1) * SZ, n);
            for (int j = L; j < R; j++) {
                a[j] += blockAdd[id];
            }
            blockAdd[id] = 0;
            // todo
        }
    };
        
    for (int t = 0; t < m; t++) {
        //db(t);
        int op = rnd() % 4 + 1;
        int l = rnd() % n;
        int r = rnd() % n;
        if (l > r) {
            swap(l, r);
        }
        r++;

        ll sl = l;
        ll sr = r;

        ll x = -1, y = -1;
        if (op == 3) {
            x = rnd() % (r - l);
        }
        else {
            x = rnd() % vmax + 1;
        }
        if (op == 4) {
            y = rnd() % vmax + 1;
        }
        //cerr << op << " " << l + 1 << " " << r << " " << x << " " << y << endl;

        //db(op);
        if (op == 1) {
            for (; l < r; ) {
                int id = l / SZ;
                if (l % SZ == 0 && l + SZ <= r) {
                    if (blockVal[id] != -1) {
                        blockVal[id] += x;
                    }
                    else {
                        blockAdd[id] += x;
                    }
                    l += SZ;
                }
                else {
                    apply(id);
                    for (; l < r && l < (id + 1) * SZ; l++) {
                        a[l] += x;
                    }
                    rebuildMP(id);
                }
            }
        }      
        if (op == 2) {
            for (; l < r; ) {
                int id = l / SZ;
                if (l % SZ == 0 && l + SZ <= r) {
                    blockAdd[id] = 0;
                    blockVal[id] = x;
                    l += SZ;
                }
                else {
                    apply(id);
                    for (; l < r && l < (id + 1) * SZ; l++) {
                        a[l] = x;
                    }
                    rebuildMP(id);
                }
            }
        }
        if (op == 3 || op == 4) {
            map<ll, int> cc;
            for (; l < r; ) {
                int id = l / SZ;
                if (l % SZ == 0 && l + SZ <= r) {
                    if (blockVal[id] == -1) {
                        for (auto w: mp[id]) {
                            cc[w.F + blockAdd[id]] += w.S;
                        }
                    }
                    else {
                        cc[blockVal[id]] += SZ;
                    }
                    l += SZ;
                }
                else {
                    apply(id);
                    rebuildMP(id);
                    for (; l < r && l < (id + 1) * SZ; l++) {
                        cc[a[l]]++;
                    }
                }
            }
            //db(cc.size());
            ll total = 0;
            for (auto w: cc) {
                total += w.S;
            }
            assert(total == sr - sl);
            if (op == 3) {
                ll res = -1;
                //db(x);
                for (auto w: cc) {
                    if (x < w.S) {
                        res = w.F;
                        break;
                    }
                    else {
                        x -= w.S;
                    }
                } 
                //db(res);
                //for (auto xx: cc) {
                    //db2(xx.F, xx.S);
                //}
                assert(res != -1);
                printf("%lld\n", res);
            }
            else {
                ll answer = 0;
                for (auto w: cc) {
                    //db3(w.F, x, y);
                    //db3(answer, binPow(w.F, x, y), w.S);
                    answer = (answer + binPow(w.F, x, y) * w.S) % y;
                }
                assert(answer >= 0);
                printf("%lld\n", answer);
            }
        }
    }



#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}