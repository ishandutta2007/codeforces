#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    vector <int> in(n);
    for (int &v: in) {
        scanf("%d", &v);
    }

    sort(in.begin(), in.end());

    if (n == 2) {
        if (in[0] + in[1] == 0) {
            printf("%lld\n", 1LL * in[0] * in[1]);
        } else {
            puts("INF");
        }

        return;
    }

    auto events = in;
    events.pop_back();
    reverse(events.begin(), events.end());
    events.pop_back();
    for (int &v: events) v *= -1;

    long long const_value = 1LL * in[0] * in[n - 1];
    long long coef = in[0] + in[n - 1];

    for (int i = 1; i + 1 < n; ++i) {
        const_value += 1LL * in[n - 1] * in[i];
        coef += in[n - 1] + in[i];
    }

    if (coef < 0) {
        puts("INF");
        return;
    }

    long long ans = const_value + events[0] * coef;
    for (int v: events) {
        ans = max(ans, const_value + v * coef);
        const_value -= 1LL * in[n - 1] * (-v);
        const_value += 1LL * in[0] * (-v);
        coef += in[0] - in[n - 1];
        ans = max(ans, const_value + v * coef);
    }

    if (coef > 0) {
        puts("INF");
        return;
    }

    printf("%lld\n", ans);
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}