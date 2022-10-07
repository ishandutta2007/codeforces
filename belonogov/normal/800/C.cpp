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
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef double dbl;


ll rev(ll a, ll m) {
    if (a == 0) return 0;
    return (((1 - rev(m % a, a) * m) / a) + m) % m;
}

int n, m;
vector<int> a;

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a.pb(x);
    }
}

void solve() {
    vector<int> use(m);
    for (auto x: a)
        use[x] = 1; 
    vector<vector<int>> cnt(m + 1);
    for (int i = 0; i < m; i++) {
        int gg = __gcd(i, m);
        if (use[i] == 0)
            cnt[gg].pb(i);
    }
    vector<int> need;
    vector<int> dp(m + 1);
    vector<int> par(m + 1);
    for (int i = 1; i <= m; i++) {      
        //db(i);
        if (m % i != 0) continue;
        dp[i] = cnt[i].size();
        par[i] = -1;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (dp[i] < dp[j] + sz(cnt[i]) && j < i) {
                    dp[i] = dp[j] + sz(cnt[i]);
                    par[i] = j;
                }
                if (dp[i] < dp[i / j] + sz(cnt[i]) && i / j < i) {
                    dp[i] = dp[i / j] + sz(cnt[i]);
                    par[i] = i / j;
                }
            }
        }
    }  

    //db(par[5]);

    vector<int> path;
    int v = m;
    for (; v != -1; v = par[v]) {
        //for (auto x: cnt[v])
            //cerr << x << " ";
        //cerr << endl;

        path.insert(path.end(), all(cnt[v]));
    }

    //cerr << endl;
    reverse(all(path));
    printf("%d\n", sz(path)); 


    int prev = 1;
    ll tmp = 1;
    for (auto x: path) {
        ll d = __gcd(prev, m);       
        ll rr = rev(prev / d, m / d);
        ll y = (x / d * rr) % (m / d);
        //cerr << endl;
        //cerr << endl;
        //db(rr);
        //db3("want ", prev, x);
        //db3(y * prev % m, d, x);
        //db3(y, prev, x);
        assert(prev * y % m == x);
        printf("%lld ", y);
        tmp = (tmp * y) % m;
        assert(use[tmp] == 0);
        use[tmp] = 1;
        prev = x;
    }





}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    if (1) {
        read();
        solve();
    } 
    else {
        for (int tt = 0;; tt++) {
            db(tt);
            m = rand() % (int)2e5 + 1;
            n = rand() % m;
            set<int> g;
            for (; sz(g) < n; ) {
                g.insert(rand() % m);
            }
            a.clear();
            a.insert(a.end(), all(g));
            solve();
        }
    }
    




    
    
#ifdef HOME 
    //epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}