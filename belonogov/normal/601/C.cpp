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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 111;
const long long INF = 1e9 + 19;
const int M = 1111;

double dp[N][N * M];
int a[N];
int n, m;

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
}

void solve() {
    if (m == 1) {
        puts("1.0");
        return;
    }
    int sumMy = 0;
    for (int i = 0; i < n; i++)
        sumMy += a[i];
    dp[0][0] = 1;
    //if (1) {
        //for (int i = 0; i < n; i++)
            //for (int j = 0; j < n * m; j++)
                //for (int k = 0; k < m; k++) {
                    //if (k != a[i])
                        //dp[i + 1][j + k] += dp[i][j] / (m - 1);
                //}
    //}
    //else {
        for (int i = 0; i < n; i++) {
            double sum = 0; 
            for (int j = 0; j <= n * (m - 1); j++) {
                sum += dp[i][j] / (m - 1);     
                if (j >= m)
                    sum -= dp[i][j - m] / (m - 1);
                dp[i + 1][j] += sum;
                if (j >= a[i])
                    dp[i + 1][j] -= dp[i][j - a[i]] / (m - 1);
            }
        }
    //}
    //double all = 0;
    //for (int i = 0; i <= n * (m - 1); i++)
        //all += dp[n][i];
    //assert(abs(all - 1) < 1e-9);
    double p = 0;
    //db(sumMy);
    for (int i = 0; i < sumMy; i++)
        p += dp[n][i];
    //db(p);
    p *= (m - 1);
    printf("%.17f\n", p + 1);

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}