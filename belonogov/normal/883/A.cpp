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
const ll INF18 = 2e18;
typedef vector<int> vi;


ll fast(ll n, ll m, ll a, ll d, vector<ll> t) {
    set<ll> used;
    t.pb(a);
    t.pb(a * n);
    for (int i = 0; i < m; i++) {
        ll k = t[i] / a;
        for (int tt = 0; tt < 2; tt++) {
            ll f = k + tt; 
            if (1 <= f && f <= n && used.count(f) == 0) {
                t.pb(f * a);
            }
        }
    }

    sort(all(t));
    t.resize(unique(all(t)) - t.begin());
    ll answer = 0;
    ll lastClose = -INF18;
    //dbv(t);
    for (int i = 0; i < sz(t); i++) {
        if (lastClose < t[i]) {
            answer++;
            lastClose = t[i] + d;
        }
        //db3(t[i], answer, lastClose);
        if (i + 1 < sz(t)) {
            ll posA = lastClose / a + 1;
            if (lastClose < t[i + 1] && posA * a <= t[i + 1]) {
                //db(posA);
                if (1 <= posA && posA <= n) {
                    //db("IN");
                    ll step = d / a + 1;
                    ll nxtPos = min(n, t[i + 1] / a);
                    ll superCnt = (nxtPos - posA) / step;
                    //assert(superCnt >= 0);
                    answer += superCnt + 1;
                    posA += superCnt * step;
                    lastClose = posA * a + d;
                }
            }
        }
    }
    return answer;
}


ll slow(ll n, ll, ll a, ll d, vector<ll> t) {
    for (int i = 1; i <= n; i++) {
        t.pb(i * a);
    }
    sort(all(t));
    ll last = -1;
    ll answer = 0;
    for (auto x: t) {
        if (last < x) {
            answer++;
            last = x + d;
        }
    }

    return answer;

}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    if (1) {
        ll n, m, a, d;
        cin >> n >> m >> a >> d; 
        vector<ll> t(m);
        for (int i = 0; i < m; i++) {
            scanf("%lld", &t[i]);
        }
        cout << fast(n, m, a, d, t) << endl;
        //cout << slow(n, m, a, d, t) << endl;
    }
    else {
        for (int tt = 0; ; tt++) {
            db(tt);
            ll C = 30;
            ll n = rand() % C + 1;
            ll m = rand() % C + 1;
            ll a = rand() % C + 1;
            ll d = rand() % C + 1; 
            vector<ll> t;
            for (int i = 0; i < m; i++) {
                t.pb(rand() % C + 1);
            }
            //cerr << n << " " << m << " " << a << " " << d << endl;
            //for (auto x: t) {
                //cerr << x << " ";
            //}
            //cerr << endl;
            auto r1 = fast(n, m, a, d, t);
            auto r2 = slow(n, m, a, d, t);
            db2(r1, r2);
            assert(r1 == r2);
        }
    }
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}