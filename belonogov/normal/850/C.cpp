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
#define forn(i, n) for (ll i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (ll)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const ll N = -1;
const ll INF = 1.01e9;
typedef vector<ll> vi;


vector<pair<ll,ll>> factor(ll x) {
    vector<pair<ll,ll>> res;
    for (ll i = 2; i * i <= x; i++) {
        ll cnt = 0;
        for (; x % i == 0; x /= i)
            cnt++;
        res.pb({i, cnt});
    }
    if (x > 1)
        res.pb({x, 1});
    return res;
}




map<ll,int> data;

ll stepMask(ll mask, ll shift) {
    ll low = (mask & (pw(shift) - 1));  
    ll high = mask - low;
    ll nmask = low | (high >> shift);
    return nmask;
}

ll rec(int mask) {
    assert(mask != 0);
    if (mask == 1) {
        return 0;
    }
    if (data.count(mask)) {
        return data[mask];
    }
    ll mex = 0;
    for (ll shift = 1; pw(shift) <= mask; shift++) {
        ll nmask = stepMask(mask, shift);
        ll res = rec(nmask);
        mex |= pw(res);
    }
    ll res = 0;
    for (; (mex & pw(res)) != 0; res++);
    data[mask] = res;
    return res;
};

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    ll n;
    scanf("%lld", &n);
    vector<ll> a(n);
    set<ll> used; 
    forn(i, n) {
        scanf("%lld", &a[i]);
        auto tmp = factor(a[i]);
        for (auto x: tmp)
            if (x.S != 0)
                used.insert(x.F);
    }

    ll answer = 0;

    for (auto cand: used) {
        ll mask = 1;
        for (auto x: a) {
            ll cnt = 0;
            for (; x % cand == 0; x /= cand, cnt++);
            mask |= pw(cnt);
        }
        assert(mask != 0);
        ll q = rec(mask);
        //db2(mask, q);
        answer ^= q;
    }

    //db(data.size());

    if (answer == 0) {
        puts("Arpa");
    }
    else {
        puts("Mojtaba");
    }







    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}