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

#define maxN 400011
#define mod 1000000007LL

int n, k, i;
pair<int, int> I[maxN];
vector<int> x;

ll comb[maxN];
int smen[maxN];

ll ans;



ll poww(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &I[i].first, &I[i].second);
        I[i].second++;
        x.pb(I[i].first);
        x.pb(I[i].second);
    }

    comb[k] = 1;
    for (i = k + 1; i <= n; i++) {
        comb[i] = (comb[i - 1] * i) % mod;
        comb[i] = (comb[i] * poww(i - k, mod - 2)) % mod;
    }

    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());

    for (i = 1; i <= n; i++) {
        int p = lower_bound(x.begin(), x.end(), I[i].first) - x.begin() + 1;
        smen[p]++;

        p = lower_bound(x.begin(), x.end(), I[i].second) - x.begin() + 1;
        smen[p]--;
    }

    for (i = 1; i < x.size(); i++) {
        smen[i] += smen[i - 1];

        ans += ( 1LL * (x[i] - x[i - 1]) * comb[smen[i]] ) % mod;
        if (ans >= mod) ans -= mod;
    }

    printf("%lld", ans);



    return 0;
}