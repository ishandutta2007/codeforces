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
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
typedef long double dbl;
typedef long long ll;
const int N = 2222;
const ll INF = 1.01e9;
typedef vector<int> vi;


ll a[N][N];


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    ll cheap = INF;
    vector<int> where;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            scanf("%lld", &a[i][j]);
            if (a[i][j] < cheap) {
                cheap = a[i][j];
                where.clear();
            }
            if (a[i][j] == cheap) {
                where.pb(i);
                where.pb(j);
            }
            a[j][i] = a[i][j];
        }
    }
    vector<ll> dp(n, 1e18);
    

    sort(all(where));
    where.erase(unique(all(where)), where.end());
    vector<int> used(n, 0);

    assert(!where.empty());
    for (auto v: where) {
        dp[v] = cheap * 1ll *  (n - 1);
    }

    for (int v = 0; v < n; v++) {
        ll mn = INF;
        for (int i = 0; i < n; i++) {
            if (i == v) continue;
            mn = min(mn, a[v][i]);
        }
        dp[v] = min(dp[v], cheap * 1ll * (n - 1) - cheap *  2 + mn * 2);
    }




    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (used[j]) continue;
            if (v == -1 || dp[v] > dp[j]) {
                v = j;
            }
        }
        //db2(v, dp[v]);
        used[v] = 1;
        for (int u = 0; u < n; u++) {
            if (u == v) continue;
            dp[u] = min(dp[u], dp[v] - cheap + a[v][u]);
        }
    }


    for (int i = 0; i < n; i++)
        printf("%lld\n", dp[i]);
    puts("");

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}