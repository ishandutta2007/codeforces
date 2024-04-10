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

#define maxN 33
#define mod 1000000007

int q, i;
ll px1, px2, py1, py2, k;

ll cnt[maxN][2][2][2];
ll dp[maxN][2][2][2];

void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a %= mod;
}

ll solve(ll x, ll y) {
    ll i, bit_x, bit_y, bit, px, py, pk, bit_k, gx, gy, gk;
    int fx, fy, fk;

    if (x < 0 || y < 0) return 0;

    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));

    dp[31][1][1][1] = 0;
    cnt[31][1][1][1] = 1;

    for (bit = 31; bit > 0; bit--) {
        bit_x = (x >> (bit - 1)) & 1;
        bit_y = (y >> (bit - 1)) & 1;
        bit_k = (k >> (bit - 1)) & 1;

        for (fx = 0; fx < 2; fx++) {
            for (fy = 0; fy < 2; fy++) {
                for (fk = 0; fk < 2; fk++) {

                    if (dp[bit][fx][fy][fk] == 0 && cnt[bit][fx][fy][fk] == 0) continue;

                    for (px = 0; px < 2; px++) {
                        for (py = 0; py < 2; py++) {
                            pk = px ^ py;

                            if (fx == 1 && bit_x == 0 && px == 1) continue;
                            if (fy == 1 && bit_y == 0 && py == 1) continue;
                            if (fk == 1 && bit_k == 0 && pk == 1) continue;

                            gx = fx && (bit_x == px);
                            gy = fy && (bit_y == py);
                            gk = fk && (bit_k == pk);

                            add(cnt[bit - 1][gx][gy][gk], cnt[bit][fx][fy][fk]);
                            add(dp[bit - 1][gx][gy][gk], dp[bit][fx][fy][fk] +
                                                         cnt[bit][fx][fy][fk] * pk * (1LL << (bit - 1)));
                        }
                    }

                }
            }
        }
    }

    ll ans = 0;

    for (fx = 0; fx < 2; fx++)
        for (fy = 0; fy < 2; fy++)
            for (fk = 0; fk < 2; fk++)
                add(ans, dp[0][fx][fy][fk] + cnt[0][fx][fy][fk]);

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> px1 >> py1 >> px2 >> py2 >> k;
        px1--; px2--;
        py1--; py2--;
        k--;

        ll ans = solve(px2, py2);
        ans += mod - solve(px1 - 1, py2);
        ans += mod - solve(px2, py1 - 1);
        ans += solve(px1 - 1, py1 - 1);
        ans %= mod;

        cout << ans << '\n';
    }


    return 0;
}