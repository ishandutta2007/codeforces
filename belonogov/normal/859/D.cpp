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

struct pt {
    int id;
    double score;
    double prob;
};


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    int m = pw(n);
    vector<vector<double>> prob(m, vector<double> (m));    
    forn(i, m) {
        forn(j, m) {
            scanf("%lf", &prob[i][j]);
            prob[i][j] /= 100;
        }
    }

    vector<vector<vector<pt>>> dp(n + 1); 
    dp[0].resize(m);
    forn(i, m) {
        dp[0][i].pb({i, 0, 1});
    }


    for (int level = 1; level <= n; level++) {
        dp[level].resize(m >> level);
        for (int i = 0; i < (m >> level); i++) {
            int v = i * 2; 
            int u = i * 2 + 1;
            forn(tt, 2) {
                for (auto x: dp[level - 1][v]) {
                    double pp = 0;
                    double mxLoser = 0;
                    for (auto y: dp[level - 1][u]) {
                        pp += prob[x.id][y.id] * y.prob;
                        mxLoser = max(mxLoser, y.score);
                    } 
                    pp *= x.prob;
                    double cc = x.score + mxLoser + pw(level - 1) * pp;
                    dp[level][i].pb({x.id, cc, pp});
                }
                swap(v, u);
            }
        }
    }

    double answer = 0;
    for (auto x: dp[n][0]) {
        answer = max(answer, x.score);
    }
    printf("%.17f\n", answer);

        
    


    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}