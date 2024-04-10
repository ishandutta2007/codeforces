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

const ll limit = 1000000000LL;

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = min(limit, ans * a);
        b >>= 1;
        a = min(limit, a * a);
    }

    return ans;
}

int n, l, r;
int i;

int cnt[maxN];

ll ans;
ll pows[maxN];
ll act[maxN];
bool dead[maxN];

void pre() {
    ll i, j;
    ll aux, cnnt, to, loc;

    for (i = 1; i <= r; i++)
        act[i] = i;

    pows[1] = 1;

    for (i = 2; i <= r; i++) {
        pows[i] = poww(i, n);
        if (pows[i] > r) break;

        if (dead[i]) {
            continue;
        } else {
            for (j = i * i; j <= r; j += i) {
                dead[j] = true;
                while (act[j] % pows[i] == 0)
                    act[j] /= pows[i];
            }
        }
    }

    for (i = l; i <= r; i++) {
        ans += cnt[ act[i] ];
        cnt[ act[i] ]++;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &l, &r);

    if (n == 1) {
        printf("%d", r - l + 1);
        return 0;
    }

    if (n == 2) {
        ll how_many = (r - l + 1);
        printf("%lld", how_many * (how_many - 1));
        return 0;
    }

    n--;
    pre();

    ans *= 2LL;
    printf("%lld", ans);


    return 0;
}