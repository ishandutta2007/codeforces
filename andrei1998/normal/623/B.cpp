#include <bits/stdc++.h>

#define lint long long int
using namespace std;

const int NMAX = 1000005;

int n, a, b;
int v[NMAX];

const lint INF = 1e18 + 15;

lint dp_pref[NMAX];
lint dp_suf[NMAX];

lint calc_dps(int m) {
    for (int i = 1; i <= n; ++ i)
        if (v[i] % m == 0)
            dp_pref[i] = dp_pref[i - 1];
        else if ((v[i] + 1) % m == 0 || (v[i] - 1) % m == 0)
            dp_pref[i] = dp_pref[i - 1] + b;
        else
            dp_pref[i] = INF;

    dp_suf[n + 1] = 0;
    for (int i = n; i; -- i)
        if (v[i] % m == 0)
            dp_suf[i] = dp_suf[i + 1];
        else if ((v[i] + 1) % m == 0 || (v[i] - 1) % m == 0)
            dp_suf[i] = dp_suf[i + 1] + b;
        else
            dp_suf[i] = INF;

    lint ans = dp_suf[1];

    //for (int i = 1; i <= n; ++ i) {
    //    cout << i << ' ' << dp_pref[i] << ' ' << dp_suf[i] << endl;
    //}

    //Luam un sufix
    lint best = 0;
    for (int i = 1; i <= n; ++ i) {
        lint aux = dp_suf[i] + (i - 1ll) * a + best;

        if (aux < ans)
            ans = aux;
        best = min(best, dp_pref[i] - 1ll * a * i);
    }

    //Mai e cazul cand nu luam un sufix
    for (int i = 1; i <= n; ++ i) {
        lint aux = dp_pref[i] + 1ll * (n - i) * a;

        if (aux < ans)
            ans = aux;
    }

    return ans;
}

lint test(int nr) {
    lint best = INF;

    for (int i = 2; i * i <= nr; ++ i)
        if (nr % i == 0) {
            best = min(best, calc_dps(i));

            while (nr % i == 0)
                nr /= i;
        }

    if (nr > 1)
        best = min(best, calc_dps(nr));

    return best;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    lint ans = INF;

    ans = min(ans, test(v[1]));
    ans = min(ans, test(v[1] + 1));
    ans = min(ans, test(v[1] - 1));
    ans = min(ans, test(v[n]));
    ans = min(ans, test(v[n] + 1));
    ans = min(ans, test(v[n] - 1));

    cout << ans << '\n';
    return 0;
}