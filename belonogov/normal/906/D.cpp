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
const ll INF18 = 1e18;
typedef vector<int> vi;


ll binPow(ll a, ll b, int mod) {
    ll res = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
    }
    return res;
}

vector<ll> fast(int m, vector<int> w, vector<pair<int,int>> query) {
    const int T = 1e5;
    vector<ll> lp(T);
    vector<ll> pr;
    for (int i = 2; i < T; i++) {
        //db2(i, pr.size());
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0; j < sz(pr) && pr[j] * i < T && pr[j] <= lp[i]; j++) {
            lp[pr[j] * i] = pr[j];
        }
    }
    //dbv(pr);
    
    auto calcFi = [&](ll p) {
        ll fi = 1;
        for (auto x: pr) {
            if (p % x == 0) {
                ll tmp = x - 1;
                p /= x;
                for (; p % x == 0; p /= x) {
                    tmp *= x;
                }
                fi *= tmp;
            }
        }
        if (p != 1) {
            fi *= p - 1;
        }
        return fi;
    };
    vector<ll> mods;
    mods.pb(m);
    for (;mods.back() > 1;) {
        mods.pb(calcFi(mods.back())); 
    }
    //dbv(mods);

    auto getReal = [&](int l, int r) {
        int firstOne = -1; 
        for (int i = l; i < r && i < l + 6; i++) {
            if (w[i] == 1) {
                firstOne = i;
                break;
            }
        }
        if (r - l < 6 && firstOne == -1) {
            firstOne = r;
        }
        if (firstOne == -1) {
            return -1ll;
        }
        ll res = 1;
        for (int j = firstOne - 1; j >= l; j--) {
            ll tmp = 1; 
            for (int t = 0; t < res; t++) {
                if (tmp * 1.0 * w[j] > INF18) {
                    return -1ll;
                }
                tmp *= w[j];
            }
            res = tmp;
        }
        return res;
    };

    function<ll(int, int, int)> getF = [&](int l, int r, int pos) {
        ll mod = mods[pos];
        if (mods[pos] == 1) {
            return 0ll;
        }
        if (l + 1 == r) {
            return w[l] % mod;
        }
        ll remPw = getF(l + 1, r, pos + 1);
        ll realRem = getReal(l + 1, r);
        if (realRem == -1) {
            return binPow(w[l], remPw + mods[pos + 1] * INF, mod);
        }
        else {
            return binPow(w[l], realRem, mod);
        }
    };

    vector<ll> answer;
    for (int i = 0; i < sz(query); i++) {
        int l = query[i].F;
        int r = query[i].S;
        answer.pb(getF(l, r, 0));
    }
    return answer;
}

vector<ll> slow(int m, vector<int> w, vector<pair<int,int>> query) {
    ll megaMod = 1;
    for (ll i = 1; i <= 22; i++) {
        ll d = __gcd(megaMod, i);
        megaMod = megaMod / d * i;
    }
    //db(megaMod);
    assert(megaMod % m == 0);
    vector<ll> answer;
    //db(query.size());
    for (auto x: query) {
        int l = x.F;
        int r = x.S;
        ll res = 1;
        for (int i = r - 1; i >= l; i--) {
            res = binPow(w[i], res, megaMod);
        }
        res %= m;
        answer.pb(res);
    }
    return answer;
}

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    if (1) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> w(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &w[i]);
        }
        int k;
        scanf("%d", &k);
        db(k);
        vector<pair<int,int>> query(k);
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &query[i].F, &query[i].S);
            query[i].F--;
        }
        //db(query.size());
        auto res = fast(m, w, query);
        //auto res = slow(m, w, query);
        //db(res.size());
        for (auto x: res) {
            cout << x << "\n";
        }
    }
    else {
        for (int tt = 0;; tt++) {
            db(tt);
            int n = rand() % 100 + 1; 
            int m = rand() % 22 + 1;
            vector<int> w;
            for (int i = 0; i < n; i++) {
                w.pb(rand() % 10 + 1);
            }
            int k = 1;
            vector<pair<int,int>> query;
            for (int i = 0; i < k; i++) {
                int l = rand() % n;
                int r = rand() % n;
                if (l > r) {
                    swap(l, r);
                }
                query.pb({l, r + 1});
            }
            auto r1 = fast(m, w, query);
            auto r2 = slow(m, w, query);
            //dbv(r1);
            assert(r1 == r2);
        }
    }
       
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}