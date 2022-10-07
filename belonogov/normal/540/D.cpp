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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = 111;
const int INF = 1e9;

double dp[N][N][N];
int x[3];
double ans[3];

void read() {
    for (int i = 0; i < 3; i++)
        cin >> x[i];
}


void solve() {
    dp[x[0]][x[1]][x[2]] = 1;
    int sum = x[0] + x[1] + x[2];
    for (int s = sum; s > 0; s--) {
        for (int i = 0; i <= x[0]; i++)
            for (int j = 0; j <= x[1]; j++) {
                int k = s - i - j;
                if (k < 0) continue;
                int pr = i * j + i * k + k * j;
                if (pr == 0) continue;
                //cerr << "i j k: " << i << " " << j << " " << k << " " << endl;
                //if (dp[i][j][k] < 1e-9) continue;
                //cerr << "---------\n";
                if (i > 0) dp[i - 1][j][k] += dp[i][j][k] * (k * i) * 1.0 / pr;
                if (j > 0) dp[i][j - 1][k] += dp[i][j][k] * (i * j) * 1.0 / pr;
                if (k > 0) dp[i][j][k - 1] += dp[i][j][k] * (j * k) * 1.0 / pr;
            }
    }
    //for (int i = 0; i <= x[0]; i++, cerr << endl)
        //for (int j = 0; j <= x[1]; j++, cerr << endl)
            //for (int k = 0; k <= x[2]; k++)
                //epr("%.3lf ", dp[i][j][k]);
    for (int i = 1; i <= x[0]; i++)
        ans[0] += dp[i][0][0];
    for (int i = 1; i <= x[1]; i++)
        ans[1] += dp[0][i][0];
    for (int i = 1; i <= x[2]; i++)
        ans[2] += dp[0][0][i];
    
    for (int i = 0; i < 3; i++)
        printf("%.15f ", ans[i]);
    printf("\n");

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