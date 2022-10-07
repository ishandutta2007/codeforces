#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 1e5 + 10;
const int INF = 1e9;
const int T = 600;
const double eps15 = 1e-40;

int n, k;
double dp[2][T];
double p[2][T];
double ans;


void read() {
    scanf("%d%d", &n, &k);
}

void solve() {
    double kof;
    dp[0][0] = 0;
    p[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < T; j++)
            dp[1][j] = p[1][j] = 0;
        for (int j = 0; j < T; j++) {
            if (p[0][j] < eps15) 
                p[0][j] = 0;
            if (dp[0][j] < eps15)
                dp[0][j] = 0;
        }
        for (int j = 0; j < T - 1; j++) {
            p[1][j] += p[0][j] * (k - 1) * 1.0 / k;
            dp[1][j] += dp[0][j] * (k - 1) * 1.0 / k;

            kof = 1.0 / k * (j + 1) / (j + 2);
            dp[1][j] += dp[0][j] * kof + kof * p[0][j] * j / 2;
            p[1][j] += p[0][j] * kof;

            kof = 1.0 / k / (j + 2);
            dp[1][j + 1] += dp[0][j] * kof + j * p[0][j] * kof;
            p[1][j + 1] += kof * p[0][j];
        }
        for (int j = 0; j < T; j++) {
            dp[0][j] = dp[1][j];
            p[0][j] = p[1][j];
        }
    }
    for (int i = 0; i < T; i++)
        ans += dp[0][i];
    ans *= k;
    ans += n;
}

void printAns() {
    //for (int i = 0; i <= n; i++, cerr << endl)
        //for (int j = 0; j <= 3; j++)
            //cerr << dp[i][j] << " ";
    //cerr << endl;
    //for (int i = 0; i <= n; i++, cerr << endl)
        //for (int j = 0; j <= 3; j++)
            //cerr << p[i][j] << " ";
    //cerr << endl;
    printf("%.15lf\n", ans);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}