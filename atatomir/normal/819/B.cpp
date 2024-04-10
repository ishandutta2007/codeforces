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

#define maxN 2000011

int n, i;
int p[maxN];
ll act, mask, last;
vector<int> wh[maxN];
pair<ll, int> best;

ll abss(ll x) {
    if (x < 0) return -x;
    return x;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &p[i]), p[i + n] = p[i];

    for (i = 1; i <= n; i++) {
        act += abss(p[i] - i);
        if (i > p[i]) {
            mask--;
            wh[1 + i - p[i]].pb(i);
        } else {
            mask++;
        }
    }

    best = mp(act, 0);
    for (i = 2; i <= n; i++) {
        last = i + n - 1;

        //! remove prev element
        act -= abss(p[i - 1] - 1);
        mask--;

        //! add modifs
        act += mask;

        //! add last element
        if (n > p[last]) {
            mask--;
            wh[i + n - p[last]].pb(last);
        } else {
            mask++;
        }
        act += abss(p[last] - n);

        //! make changes
        for (auto e : wh[i]) mask += 2;

        best = min(best, mp(act, (3 * n - i + 1) % n));
    }

    printf("%lld %d", best.first, best.second);



    return 0;
}