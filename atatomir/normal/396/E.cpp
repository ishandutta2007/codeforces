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

#define maxN 1000011

const int def = 1000000;

ll n, i, k;
ll p, x;

vector< pair<ll, ll> > divs[maxN], intr[maxN], aux;
bool prime[maxN];

ll ans[maxN];

void pre() {
    ll i, j, cnt, x, pp;

    for (i = 1; i <= def; i++)
        divs[i].reserve(5);


    for (i = 2; i <= def; i++) {
        if (divs[i].size()) continue;
        prime[i] = true;

        for (j = i; j <= def; j += i) {
            cnt = 0;
            x = j;

            while (x % i == 0) cnt++, x /= i;
            divs[j].pb(mp(i, cnt));
        }
    }
}

void solve(int id) {
    ll i, cnt;

    if (intr[id].empty()) return;

    aux = intr[id];
    intr[id].clear();
    sort(aux.begin(), aux.end());

    intr[id].pb(aux[0]);
    for (i = 1; i < aux.size(); i++) {
        if (aux[i].first > intr[id].back().second)
            intr[id].pb(aux[i]);
        else
            intr[id].back().second += aux[i].second - aux[i].first + 1;
    }

    for (i = 0; i < intr[id].size(); i++) {
        if (intr[id][i].second <= k) continue;

        if (intr[id][i].first <= k) {
            ans[id] += intr[id][i].second - k;
            intr[id][i].second = k;
        } else {
            ans[id] += intr[id][i].second - intr[id][i].first + 1;
            intr[id][i] = intr[id].back();
            intr[id].pop_back();
            i--;
        }
    }

    for (auto act : intr[id]) {
        for (auto e : divs[id - 1]) {
            for (cnt = 1; cnt <= e.second; cnt++)
                intr[e.first].pb(mp(act.first + 1, act.second + 1));
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    pre();
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld", &p, &x);

        intr[p].pb(mp(1, x));
    }
    scanf("%lld", &k);

    for (i = def; i >= 2; i--)
        solve(i);

    ll sol = 0;
    for (i = 1; i <= def; i++)
        if (ans[i])
            sol++;

    printf("%lld\n", sol);
    for (i = 1; i <= def; i++)
        if (ans[i])
            printf("%lld %lld\n", i, ans[i]);


    return 0;
}