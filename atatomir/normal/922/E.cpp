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

#define maxN 10011

const ll inf = 1LL << 60;

ll n, W, B, X, m, i;
ll cost[maxN], cnt[maxN], cc[maxN];
ll bonus[maxN];

ll ss, dd;
ll dp[2][maxN];

void clean_up(ll* data) {
    static ll i;
    for (i = 0; i <= m; i++) data[i] = -inf;
}

void upd(ll& a, ll b) {
    a = max(a, b);
}

int main()
{
  //  freopen("test.in","r",stdin);

    cin >> n >> W >> B >> X;
    for (i = 1; i <= n; i++) cin >> cnt[i];
    for (i = 1; i <= n; i++) cin >> cc[i];

    for (i = 1; i <= n; i++) {
        bonus[m] = X;
        while (cnt[i] > 0) {
            cnt[i]--;
            cost[++m] = cc[i];
        }
    }

    ss = 0; dd = 1;
    clean_up(dp[ss]);
    dp[ss][0] = W;

    for (int step = 1; step <= m; step++) {
        clean_up(dp[dd]);

        for (i = 0; i < step; i++) {
            if (dp[ss][i] < 0) continue;
            upd(dp[dd][i], min(dp[ss][i] + bonus[step], W + i * B));
            if (dp[ss][i] >= cost[step]) {
                upd(dp[dd][i + 1], min(dp[ss][i] - cost[step] + bonus[step], W + (i + 1) * B));
            }
        }

        swap(ss, dd);
    }

    for (i = m; dp[ss][i] < 0; i--);
    cout << i;


    return 0;
}