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

#define maxN 5011
#define inf (1LL << 60)
#define act dp[ss][n1][n2][n3]

int n, i, n1, n2, n3, s, e;
ll a[maxN], b[maxN], c[maxN], d[maxN], x[maxN];
int ss, dd;
ll dp[2][maxN][2][2];
ll ans = inf;



void clr(int id) {
    for (n1 = 0; n1 <= n; n1++)
        for (n2 = 0; n2 < 2; n2++)
            for (n3 = 0; n3 < 2; n3++)
                dp[id][n1][n2][n3] = inf;
}

void ini_state() {
    clr(ss);

    if (1 == s) {
        dp[ss][0][1][0] = d[1];
        return;
    }

    if (1 == e) {
        dp[ss][0][0][1] = b[1];
        return;
    }

    dp[ss][1][0][0] = b[1] + d[1];
}

void best(ll &dest, const ll &a) {
    dest = min(dest, a);
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &s, &e);
    for (i = 1; i <= n; i++) scanf("%lld", &x[i]);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (i = 1; i <= n; i++) scanf("%lld", &b[i]);
    for (i = 1; i <= n; i++) scanf("%lld", &c[i]);
    for (i = 1; i <= n; i++) scanf("%lld", &d[i]);


    ss = 0; dd = 1;
    ini_state();

    for (i = 2; i <= n; i++) {
        clr(dd);

        for (n1 = 0; n1 <= i; n1++) {
            for (n2 = 0; n2 < 2; n2++) {
                for (n3 = 0; n3 < 2; n3++) {
                    if (act >= inf) continue;

                    ll bonus = (x[i] - x[i - 1]) * (2 * n1 + n2 + n3);

                    //! is the start
                    if (i == s) {
                        if (n2 == 1) continue;

                        best(dp[dd][n1][1][n3], act + bonus + d[i]); // new path
                        if (n1 > 0)
                            best(dp[dd][n1 - 1][1][n3], act + bonus + c[i]); // jumping

                        if (n1 == 0 && n3 == 1 && i == n)
                            best(ans, act + bonus + c[i]);

                        continue;
                    }

                    //! is the end
                    if (i == e) {
                        if (n3 == 1) continue;

                        best(dp[dd][n1][n2][1], act + bonus + b[i]); // new path
                        if (n1 > 0)
                            best(dp[dd][n1 - 1][n2][1], act + bonus + a[i]); // landing

                        if (n1 == 0 && n2 == 1 && i == n)
                            best(ans, act + bonus + a[i]);

                        continue;
                    }

                    //! is just a boring chair
                    best(dp[dd][n1 + 1][n2][n3], act + bonus + b[i] + d[i]); // new path
                    if (n1 > 0) {
                        best(dp[dd][n1][n2][n3], act + bonus + a[i] + d[i]); // landing
                        best(dp[dd][n1][n2][n3], act + bonus + c[i] + b[i]); // jumping
                        if (n1 > 1)
                            best(dp[dd][n1 - 1][n2][n3], act + bonus + a[i] + c[i]); // connect two paths
                    }

                    if (n2 == 1) {
                        best(dp[dd][n1][n2][n3], act + bonus + a[i] + d[i]); // landing
                        if (n1 > 0)
                            best(dp[dd][n1 - 1][n2][n3], act + bonus + a[i] + c[i]); // connect two paths
                    }

                    if (n3 == 1) {
                        best(dp[dd][n1][n2][n3], act + bonus + c[i] + b[i]); // jumping
                        if (n1 > 0)
                            best(dp[dd][n1 - 1][n2][n3], act + bonus + a[i] + c[i]); // connect two paths
                    }

                    if (n1 == 0 && n2 == 1 && n3 == 1 && i == n)
                        best(ans, act + bonus + a[i] + c[i]);
                }
            }
        }

        swap(ss, dd);
    }

    printf("%lld", ans);


    return 0;
}