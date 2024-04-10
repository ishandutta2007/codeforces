#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 1111;
const int INF = 1e9;
const int K = 111; 

int MOD;
int n, k;
long long dp[N][K];
long long dp2[N];

void add(long long & a, long long b) {
    a = (a + b) % MOD;
}

void read() {
    scanf("%d%d%d", &n, &k, &MOD);
    long long step = 1;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = 0;
        add(dp2[i + 1], dp2[i] * 10);
        add(ans, dp2[i] * 9);

        for (int j = 0; j < k; j++) {
            for (int x = 0; x < 10; x++) {
                int y = (j + step * x) % k;
                if (y == 0) {
                    add(dp2[i + 1], dp[i][j]);
                    if (x != 0)
                        add(ans, dp[i][j]);
                }
                else
                    add(dp[i + 1][y], dp[i][j]);
            } 
        } 
        for (int x = 1; x < 10; x++) {
            int y = (step * x) % k;
            if (y == 0) {
                add(dp2[i + 1], 1);
                add(ans, 1);
            }
            else
                add(dp[i + 1][y], 1);
        }
        step = (step * 10) % k;
    }
    printf("%lld\n", ans);
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