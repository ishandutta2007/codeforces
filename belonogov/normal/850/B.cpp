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



vector<int> lp;
vector<int> pr;
void genPrime(int n) {
    lp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] * i <= n && pr[j] <= lp[i]; j++)
            lp[i * pr[j]] = pr[j];
    }
}

vector<pair<ll,int>> factor(ll x) {
    assert(x < (int)lp.size());
    vector<pair<ll,int>> res;
    for (; x > 1; ) {
        int cnt = 0;
        ll div = lp[x];
        for (; x % div == 0; x /= div)
            cnt++;
        res.pb({div, cnt});
    }
    return res;
}




int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    ll n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    ll answer = n * x;
    int Q = 1e6 + 100;
    genPrime(Q);
    vector<int> cnt(Q);
    vector<int> a(n);
    forn(i, n) {
        scanf("%d", &a[i]);
        forn(j, 2) {
            auto tmp = factor(a[i] + j);
            for (auto h: tmp) {
                //db(h.F);
                cnt[h.F]++;
            }
        }
    }

    auto check = [&](int p) {
        //db(p);
        ll res = 0;
        for (auto t: a) {
            ll f = (p - t % p) % p;
            res += min(x, y * f);
            if (res >= answer) {
                break;
            }
        }
        answer = min(answer, res);
    };
    vector<pair<int,int>> fin;
    forn(i, Q) {
        if (cnt[i] != 0) {
            fin.pb({cnt[i], i});
        }
    }
    sort(all(fin));
    reverse(all(fin));
    //db("!");
    for (auto h: fin) {
        if (h.F == 0 || clock() * 1.0 / CLOCKS_PER_SEC > 1.9) {
            break;
        }
        check(h.S);
    }





    
    cout << answer << endl;
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}