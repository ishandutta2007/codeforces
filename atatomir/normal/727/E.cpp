#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 4000021
#define base 37
#define base2 31
#define mod 1000000007LL
#define mod2 666013

int n, k, i, m, j, dim, cnt;
char s[maxN];
char w[maxN];

ll h[maxN], h2[maxN];
ll pows[maxN], pows2[maxN];
ll act, act2;

map<ll, int> M;
vector<ll> ids;
map<ll, int> last;
bool good;

ll get_hash(int l, int r) {
    ll ans = h[r] - ((h[l - 1] * pows[r - l + 1]) % mod);
    if (ans < 0) ans += mod;

    ll ans2 = h2[r] - ((h2[l - 1] * pows2[r - l + 1]) % mod2);
    if (ans2 < 0) ans2 += mod2;

    return ans * ans2;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n%s\n", &n, &k, s + 1); n *= k;
    for (i = 1; i <= n; i++) s[n + i] = s[i];

    pows[0] = pows2[0] = 1;
    for (i = 1; i <= 2 * n; i++) {
        h[i] = (1LL * h[i - 1] * base + s[i] - 'a' + 1) % mod;
        pows[i] = (1LL * pows[i - 1] * base) % mod;

        h2[i] = (1LL * h2[i - 1] * base2 + s[i] - 'a' + 1) % mod2;
        pows2[i] = (1LL * pows2[i - 1] * base2) % mod2;
    }

    scanf("%d\n", &m);
    for (i = 1; i <= m; i++) {
        memset(w, 0, dim + 10);

        act = act2 = 0;
        scanf("%s\n", w + 1);
        dim = strlen(w + 1);
        for (j = 1; j <= dim; j++) {
            act = (act * base + w[j] - 'a' + 1) % mod;
            act2 = (act2 * base2 + w[j] - 'a' + 1) % mod2;
        }

        act *= act2;
        if (M[act] != 0) while(1);
        M[act] = i;
    }

    for (i = 1; i <= k; i++) {
        ids.clear();
        last[0] = ++cnt;
        good = true;

        for (j = 0; j < n; j += k) {
            act = get_hash(i + j, i + j + k - 1);
            ids.pb(M[act]);
            if (last[ids.back()] == cnt) {good = false; break;}
            last[ids.back()] = cnt;
        }

        if (good) {
            printf("YES\n");
            for (auto e : ids) printf("%d ", e);

            return 0;
        }
    }

    printf("NO\n");


    return 0;
}