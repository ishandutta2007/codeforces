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

#define maxN 511

const int def = 34 * 1000;

int n, i, mini, limit;
int a[maxN];

int low[def + 11];
int l, r;

void solution(int dim) {
    ll i, nr, aux;
    ll ans = 0;

    for (i = 1; i <= n; i++) {
        nr = a[i] / dim;

        ans += a[i] % dim;
        nr -= a[i] % dim;

        aux = nr / (dim + 1);
        nr -= aux * (dim + 1);
        ans += aux * dim;
        ans += nr;
    }

    printf("%lld", ans);
    exit(0);
}

void add(int val) {
    int i, dim, R;
    int limit = min(val, def);

    for (i = 1; i <= limit; i++)
        if (val / i >= val % i)
            low[i]++;
}

void check(int val) {
    int nr, dim, R, i;
    vector<int> ord;

    for (nr = 1; nr <= limit; nr++) {
        dim = val / nr;
        R = val - nr * dim;

        ord.pb(dim);
        if (R == 0) ord.pb(dim - 1);
    }

    sort(ord.begin(), ord.end());
    ord.resize(unique(ord.begin(), ord.end()) - ord.begin());
    reverse(ord.begin(), ord.end());

    for (auto dim : ord) {
        bool ok = true;

        for (i = 1; i <= n; i++) {
            if (a[i] / dim < a[i] % dim) {
                ok = false;
                break;
            }
        }

        if (ok)
            solution(dim);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n); mini = 1000000000;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]), mini = min(mini, a[i]);

    random_shuffle(a + 1, a + n + 1);

    limit = min(mini, def);
    check(a[1]);

    for (i = 1; i <= n; i++)
        add(a[i]);
    for (i = def; i > 0; i--)
        if (low[i] == n)
            solution(i);

    return 0;
}