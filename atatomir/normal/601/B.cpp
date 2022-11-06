#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011

int n, i, q, l, r;
int v[maxN];

int dim;
pair<int, int> S[maxN];
long long ans;


void solve() {
    int i;
    long long act = 0;

    S[++dim] = mp(1000000000, l);

    for (i = l + 1; i <= r; i++) {
        auto now = mp(v[i], i);

        while (dim > 0 && S[dim].first <= v[i]) {
            act -= 1LL * S[dim].first * (S[dim].second - S[dim - 1].second);
            dim--;
        }

        S[++dim] = now;
        act += 1LL * S[dim].first * (S[dim].second - S[dim - 1].second);

        ans += act;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    for (i = n; i > 0; i--) {
        v[i] -= v[i - 1];
        if (v[i] < 0)
            v[i] = -v[i];
    }

    for (; q > 0; q--) {
        scanf("%d%d", &l, &r);

        dim = 0;
        ans = 0;
        solve();

        printf("%I64d\n", ans);
    }

    return 0;
}