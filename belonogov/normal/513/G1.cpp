#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 33;
const int INF = 1e9;

int n, k;
int p[N];
double dp[2][N][N];


int go(int l, int r, int x) {
    if (x < l || r <= x) return x;
    return (r - 1 - (x - l));
}

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            dp[0][i][j] = p[i] > p[j];

    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < n; j++)
            //cerr << dp[0][i][j] << " ";

    double cof = 1.0 / (n * (n + 1) / 2);
    //cerr << "cof: " << cof << endl;
    for (int t = 0; t < k; t++) {
        memset(dp[1], 0, sizeof(dp[1]));
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int l = 0; l < n; l++)
                    for (int r = l + 1; r <= n; r++) {
                        int ii = go(l, r, i);
                        int jj = go(l, r, j);
                        if (ii < jj)
                            dp[1][ii][jj] += dp[0][i][j];
                        else {
                            //cerr << "second case " << ii << " " << jj << endl;
                            dp[1][jj][ii] += (1 - dp[0][i][j]);
                        }
                    }
        //for (int i = 0; i < n; i++, cerr << endl)
            //for (int j = 0; j < n; j++) {
                ////cerr << "i j: dp: " << " " << i << " " << j << " " << dp[1][i][j] << endl;
                ////cerr << dp[1][i][j] << " ";
            //}
            
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                //cerr << "i j: dp: " << " " << i << " " << j << " " << dp[1][i][j] << endl;
                dp[0][i][j] = dp[1][i][j] * cof;
            }

        //for (int i = 0; i < n; i++, cerr << endl)
            //for (int j = 0; j < n; j++)
                //cerr << dp[0][i][j] << " ";
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans += dp[0][i][j]; 
    printf("%.15lf\n", ans);
}

void solve() {

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
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}