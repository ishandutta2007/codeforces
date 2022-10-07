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
const int N = 2e5 + 10;
const int INF = 1.01e9;
const ll INF18 = 1.01e18;
typedef vector<int> vi;

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    ll C;
    scanf("%d%lld", &n, &C);
    vector<ll> a(n);
    vector<ll> b(n - 1);
    forn(i, n) {
        scanf("%lld", &a[i]);
        if (i + 1 != n) {
            scanf("%lld", &b[i]);
        }
    }
    b.pb(0);
    vector<ll> c(n);
    set<pair<ll,int>> q;
    ll shift = 0;
    vector<ll> hist(n);
    
    //ll sumSeg = 0;
    int cur = 0;
    vector<ll> prefB;
    prefB.pb(0);
    for (int i = 0; i < n; i++) {
        prefB.pb(prefB.back() + a[i] + b[i]);
    }
    vector<ll> prefC;
    prefC.pb(0);
    for (int i = 0; i < n; i++) {
        //db(i);
        if (i > 0) {
            ll diff = b[i - 1] - c[i - 1];
            shift += diff;

            q.insert({-shift, i});
            hist[i] = -shift;
        }
        if (i == 0) {
            q.insert({0, i});
            hist[i] = 0;
        }
        //db("me");
        for (; cur < i && (prefB[i] - prefB[cur]) + a[i] > C; ) {
            assert(q.erase({hist[cur], cur}));
            cur++;
        }         
        //db(cur);
        ll val = 0; 
        //db(val);
        //db(q.size());
        if (!q.empty()) {
            val = max(q.rbegin()->F + shift, val);
        }
        //db3("1", val, cur);
        val = max(min(prefB[i] + a[i], C) - ((prefC[i] - prefC[max(0, cur - 1)]) + a[i]), val);
        //db2("2", val);
        c[i] = val;
        prefC.pb(prefC.back() + a[i] + c[i]);
    } 
    
    ll answer = 0;
    for (auto x: c) {
        answer += x;
    }
    //dbv(c);
    for (auto x: a) {
        answer += min(x, C);
    }


    cout << answer << endl;
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}