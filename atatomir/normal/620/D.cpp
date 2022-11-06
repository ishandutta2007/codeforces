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

#define maxN 2016

int n, m, i, j, pos;
ll a[maxN], b[maxN];
ll sa, sb;

ll ans, aux;
vector<int> sol;

vector<ll> side;


ll abss(ll x) {
    if (x < 0) return -x;
    return x;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sa += a[i];
    }

    scanf("%d", &m);
    for (i = 1; i <= m; i++) {
        scanf("%lld", &b[i]);
        sb += b[i];
    }


    // zero swaps
    ans = abss(sa - sb);
    sol = {};

    // one swap
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            aux = abss( (sa - a[i] + b[j]) - (sb - b[j] + a[i]) );
            if (aux < ans) {
                ans = aux;
                sol = {i, j};
            }
        }
    }

    // two swaps
    side.clear();
    side.reserve( (m * (m - 1)) / 2 );

    for (i = 1; i <= m; i++)
        for (j = i + 1; j <= m; j++)
            side.pb(2LL * (b[i] + b[j]));

    sort(side.begin(), side.end());

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            pos = lower_bound(side.begin(), side.end(), -(sa - sb - 2 * (a[i] + a[j]))) - side.begin();

            if (pos < side.size()) {
                aux = abss(sa - sb - 2 * (a[i] + a[j]) + side[pos]);
                if (aux < ans) {
                    ans = aux;
                    sol = {i, j, side[pos] / 2};
                }
            }

            if (--pos >= 0) {
                aux = abss(sa - sb - 2 * (a[i] + a[j]) + side[pos]);
                if (aux < ans) {
                    ans = aux;
                    sol = {i, j, side[pos] / 2};
                }
            }
        }
    }

    if (sol.size() == 3) {
        bool found = false;

        for (i = 1; i <= m && !found; i++)
            for (j = i + 1; j <= m; j++)
                if (b[i] + b[j] == sol[2]) {
                    sol = {sol[0], i, sol[1], j};
                    found = true;
                    break;
                }
    }

    printf("%lld\n", ans);
    printf("%d\n", sol.size() / 2);
    for (i = 0; i < sol.size(); i += 2)
        printf("%d %d\n", sol[i], sol[i + 1]);

    return 0;
}