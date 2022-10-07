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
const int N = 333;
const ll INF = 1.01e9;
typedef vector<int> vi;
const int MOD = 1e9 + 7;

ll c[N][N];

void add(ll& A, ll B) {
    A = (A + B) % MOD;
}

ll mul(ll A, ll B) {
    return (A * B) % MOD;
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    map<vector<int>,int> q;
    ///map<vector<int>,vector<int>> f;
    c[0][0] = 1;
    forn(i, n)
        for (int j = 0; j <= i; j++) {
            add(c[i + 1][j], c[i][j]); 
            add(c[i + 1][j + 1], c[i][j]);
        }



    forn(j, n) {
        int x;
        scanf("%d", &x);
        //int xx = x;
        vector<int> tmp;
        for (int i = 2; i * i <= x; i++) {
            int cnt = 0;
            for (; x % i == 0; x /= i)
                cnt++;
            if (cnt % 2 == 1) {
                tmp.pb(i);
            }
        }
        if (x > 1) {
            tmp.pb(x);
        }
        //f[tmp].pb(xx);
        q[tmp]++;
    }
    ll mainCof = 1;
        //map<int,int> w;
        //for (auto y: x.S) {
            //w[y]++;
        //}
        //int sum = 0;
        //for (auto y: w) {
            //int cnt = y.S;
            //mainCof = mul(mainCof, c[sum + cnt][sum]);
            //sum += cnt;
        //}


    vector<int> b;
    for (auto x: q) {
        b.pb(x.S);
        for (int i = 1; i <= x.S; i++)
            mainCof = mul(mainCof, i);
    }
    //db(mainCof);

  


    int m = b.size();
    vector<vector<ll>> dp(m + 1, vector<ll>(n));
    dp[0][0] = 1; 
    vector<int> pref;
    pref.pb(0);
    for (auto x: b)
        pref.pb(pref.back() + x);
    assert(pref.back() == n);

    //db("!!");
    //db2(n, m);
    //for (auto x: b) { db(x); }
    forn(i, m) {
        forn(j, n) {
            //db2(i, j);
            if (dp[i][j] == 0) continue;
            //db3(i, j, dp[i][j]);
            ll bad = j;
            ll good = pref[i] + 1 - j;
            //db2(bad, good);
            //db(dp[m][0]);
            for (int t = 0; t <= bad && t <= b[i]; t++) {
                for (int k = 0; k <= good && k + t <= b[i]; k++) {
                    ll cof = mul(c[bad][t], c[good][k]);
                    int pos = j - t + (b[i] - t - k);
                    if (pos >= 0 && t + k > 0) {
                        //db3(t, k, cof);
                        int F = t + k;
                        int x = b[i] - t - k;
                        add(dp[i + 1][j - t + (b[i] - t - k)], mul(mul(cof, c[F + x - 1][F - 1]), dp[i][j]));
                    }
                }
            } 
        }
    }
    //db(dp[1][3]);
    //db(dp[2][1]);
    //db(dp[3][0]);



    //db(dp[m][0]);


    cout << mul(mainCof, dp[m][0]) << endl;
        







    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}