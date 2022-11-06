#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define mod 1000000007
#define maxN 79

const int vars = 20;

int n, i, j, conf, limit;
char s[maxN];
int nr[maxN][maxN];

int dp[maxN][1 << vars];


void pre() {
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            nr[i][j] = nr[i][j - 1] * 2 + s[j] - '0';
            if (nr[i][j] > 30) nr[i][j] = 30;
        }
    }
}

inline void add(int &a, const int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);
    pre();

    limit = 1 << vars;
    for (i = 1; i <= n; i++) {
        add(dp[i][0], 1);

        for (conf = 0; conf < limit; conf++) {
            if (dp[i][conf] == 0) continue;

            for (j = i; j <= n && nr[i][j] <= 20; j++) {
                if (nr[i][j] == 0) continue;
                add(dp[j + 1][ conf | (1 << (nr[i][j] - 1)) ], dp[i][conf]);
            }
        }
    }

    int ans = 0;
    conf = 0;
    for (i = 0; i < vars; i++) {
        conf |= 1 << i;

        for (j = 1; j <= n + 1; j++)
            add(ans, dp[j][conf]);
    }

    printf("%d", ans);


    return 0;
}