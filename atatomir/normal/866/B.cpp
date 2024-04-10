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

#define maxN 100011

ll n, S, i, sum_a, sum_b, sum_all;
ll s[maxN], a[maxN], b[maxN];
ll ans, sol_a, sol_b;

ll need_a, need_b, need_all;

vector< pair<ll, ll> > pizza_a, pizza_b;

ll rm(vector< pair<ll, ll> >& data, ll cnt) {
    ll aux;
    ll ans = 0;

    for (auto e : data) {
        aux = min(e.second, cnt);
        ans += aux * e.first;
        cnt -= aux;

        if (cnt == 0)
            return ans;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> S;
    for (i = 1; i <= n; i++) {
        cin >> s[i] >> a[i] >> b[i];
        if (a[i] <= b[i]) {
            ans += b[i] * s[i];
            b[i] -= a[i];
            a[i] -= a[i];

            sum_all += s[i];
            sum_b += s[i];
            pizza_b.pb(mp(b[i], s[i]));
        } else {
            ans += a[i] * s[i];
            a[i] -= b[i];
            b[i] -= b[i];

            sum_all += s[i];
            sum_a += s[i];
            pizza_a.pb(mp(a[i], s[i]));
        }
    }

    sort(pizza_a.begin(), pizza_a.end());
    sort(pizza_b.begin(), pizza_b.end());

    need_a = (sum_a + S - 1) / S;
    need_b = (sum_b + S - 1) / S;
    need_all = (sum_all + S - 1) / S;

    if (need_a + need_b == need_all) {
        cout << ans << '\n';
        return 0;
    }

    sol_a = ans - rm(pizza_a, sum_a % S);
    sol_b = ans - rm(pizza_b, sum_b % S);

    ans = max(sol_a, sol_b);
    cout << ans << '\n';

    return 0;
}