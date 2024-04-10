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
const ll INF = 1.01e9;
typedef vector<int> vi;


vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    for (ll i = 2; i * i <= x; i++) {
        int cnt = 0;
        for (; x % i == 0; x /= i)
            cnt++;
        res.pb({i, cnt});
    }
    if (x > 1)
        res.pb({x, 1});
    return res;
}





int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    ll a, b;
    cin >> a >> b;
    auto faa = factor(a);
    auto fbb = factor(b);
    auto fa = map<ll,int> (all(faa));
    auto fb = map<ll,int> (all(fbb));
    ll answer = 0;
    for (;b > 0;) {
        ll g = __gcd(a, b);
        ll tmr = b / g;
        for (auto x: fa) {
            ll p = x.F;
            ll q = 1;
            forn(i, x.S)
                q *= p;
            if (g % q != 0) {
                tmr = min(tmr, b / g % p); 
            }
        } 

        answer += tmr;
        b -= tmr * g;
    }




    cout << answer << endl;





    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}