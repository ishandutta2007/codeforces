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
const int N = 88;
const ll INF = 1.01e9;
typedef vector<int> vi;

int n, k;
vector<pair<int,int>> e[N];
int dp[N][N][N];

void upd(int& A, int B) {
    A = min(A, B);
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    scanf("%d%d", &n, &k);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int v, u, c;
        scanf("%d%d%d", &v, &u, &c); v--; u--;
        e[v].pb({u, c});
    }
    memset(dp, 63, sizeof dp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][1] = 0;
        }
    }
    //for (int v = 0; v < n; v++) {
        //for (auto x: e[v]) {
            //upd(dp[v][x.F][2], x.S);
        //}
    //}

    for (int len = 1; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            //int j = i + len;
            int v = i;
            int u = i + len; 
            for (int tt = 0; tt < 2; tt++) {

                for (int t = 2; t <= k; t++) {
                    for (auto x: e[v]) {
                        if (min(v, u) < x.F && x.F < max(v, u)) {
                            if (v < x.F)
                                upd(dp[v][u][t], dp[x.F][v + 1][t - 1] + x.S);
                            else
                                upd(dp[v][u][t], dp[x.F][v - 1][t - 1] + x.S);
                            upd(dp[v][u][t], dp[x.F][u][t - 1] + x.S);
                        }
                        if (x.F == u) {
                            if (v < u)
                                upd(dp[v][u][t], dp[x.F][v + 1][t - 1] + x.S);
                            else
                                upd(dp[v][u][t], dp[x.F][v - 1][t - 1] + x.S);
                        }
                    }
                } 
                swap(v, u);
            }
        }
    }
    //db(dp[2][3][2]);
    //db(dp[3][3][1]);


    int answer = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            answer = min(answer, dp[i][j][k]);
            answer = min(answer, dp[i][j][k]);
        }
    if (answer == INF) {
        puts("-1");
    }
    else {
        cout << answer << endl;
    }
    


    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}