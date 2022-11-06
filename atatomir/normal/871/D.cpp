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

#define maxN 10000011

ll n, i, j, p, act;
ll pr[maxN];
ll cnt[maxN];
ll lp[maxN];

bool bad[maxN];
int divs[maxN];

ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 2; i <= n; i++) {
        if (pr[i] != 0) {
            cnt[pr[i]]++;
            continue;
        }

        for (j = i; j <= n; j += i) {
            divs[j]++;
            if (pr[j] == 0) pr[j] = i;
        }

        for (j = i * i; j <= n; j += i * i)
            bad[j] = true;

        cnt[pr[i]]++;
    }

    for (i = 2; i <= n; i++) {
        while (cnt[i] > 0) {
            lp[++p] = i;
            cnt[i]--;
        }
    }

    //! add dist 1
    for (i = 2; i <= n; i++) {
        if (bad[i]) continue;
        ans += (divs[i] % 2 == 1 ? 1LL : -1LL) * (n / i) * ((n / i) - 1);
    }
    ans /= 2;
    ans *= -1;

    //! add dist 2
    act = p;
    for (i = 1; i <= p; i++) {
        while (lp[i] * lp[act] > n && act > 0) act--;
        if (act <= i) break;

        ans += 2LL * (act - i);
    }

    //! add dist 3
    act = p;
    for (i = 1; i <= p; i++) {
        while (lp[i] * lp[act] > n && act > 0) act--;
        act++;

        if (2 * lp[i] > n) break;
        if (act < i && lp[i] * lp[act] > n)
            ans += 3LL * (i - act);
    }


    cout << ans;

    return 0;
}