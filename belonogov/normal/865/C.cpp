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
const int N = 55;
const int M = 5555;
const int INF = 1.01e9;
typedef vector<int> vi;


double dp[N][M];

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, R;
    scanf("%d%d", &n, &R);
    vi f(n), s(n), p(n);
    vi d(n);
    forn(i, n) {
        scanf("%d%d%d", &f[i], &s[i], &p[i]); 
        d[i] = s[i] - f[i];
        R -= f[i];
    }

    auto check = [&](double C) {
        memset(dp, 0, sizeof dp);
        for (int i = n - 1; i >= 0; i--) {
            for (int t = 0; t <= R; t++) {
                double f1 = p[i] / 100.0 * (dp[i + 1][t] + f[i]);
                double f2;
                if (t + d[i] > R) {
                    f2 = (100 - p[i]) / 100.0 * (C + s[i]);
                }
                else {
                    f2 = (100 - p[i]) / 100.0 * (dp[i + 1][t + d[i]] + s[i]);
                }
                if (i > 0) {
                    dp[i][t] = min(C, f1 + f2);
                }   
                else {
                    dp[i][t] = f1 + f2;
                }
            }
        }
        //forn(i, n + 1) {
            //forn(j, R + 1) {
                //cerr << dp[i][j] << " ";
            //}
            //cerr << endl;
        //}
        return dp[0][0] > C;
    };
    //db2(n, R);
    //db(check(1));
    //return 0;

    double l = 0;  
    double r = 1e12;
    forn(tt, 80) {
        if (check((l + r) / 2)) {
            l = (l + r) / 2;
        }
        else {
            r = (l + r) / 2;
        }
    }

    printf("%.17f\n", l);





    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}