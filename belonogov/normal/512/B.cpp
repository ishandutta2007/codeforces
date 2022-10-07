#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 333;
const int INF = 1e9;

int n;
int l[N];
int c[N];
vector < int > p[N];
int dp[1 << 11];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &l[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
}

void solve() {
    for (int i = 0; i < n; i++) {
        int x = l[i];
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0)
                p[i].pb(j);
            for (; x % j == 0; x /= j);
        }
        if (x != 1)
            p[i].pb(x);
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        memset(dp, 63, sizeof(dp));  
        int t = p[i].size();
        dp[(1 << t) - 1] = c[i]; 
        for (int j = 0; j < n; j++) {
            int tmpMask = 0;
            for (int k = 0; k < (int)p[i].size(); k++)
                for (int t = 0; t < (int)p[j].size(); t++)
                    if (p[i][k] == p[j][t]) {
                        tmpMask |= 1 << k;
                    }
            for (int mask = 0; mask < (1 << t); mask++) {
                dp[mask & tmpMask] = min(dp[mask & tmpMask], dp[mask] + c[j]);
            }
        }
        ans = min(ans, dp[0]);
    }
    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
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