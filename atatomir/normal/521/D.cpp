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

#define maxN 100011

struct frac {
    ll a, b;

    bool operator<(const frac& who)const  {
        return a * who.b < b * who.a;
    }
};

int n, m, k, i; // n skills, m upgrades, k available upgrades
ll op, sk, pw;
ll a[maxN];
int tp[maxN];

vector< pair<ll, ll> > add[maxN];
pair<ll, ll> best[maxN];

vector< pair<frac, ll> > upg;
vector<int> sol;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);

    for (i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &op, &sk, &pw);
        tp[i] = op;

        if (op == 1)
            best[sk] = max(best[sk], mp(pw, 1LL * i));

        if (op == 2)
            add[sk].pb(mp(pw, i));

        if (op == 3)
            if (pw > 1)
            upg.pb(mp((frac){pw - 1, 1}, 1LL * i));
    }

    for (i = 1; i <= n; i++) {
        if (best[i].first > a[i])
            add[i].pb(mp(best[i].first - a[i], best[i].second));

        sort(add[i].begin(), add[i].end(), greater< pair<ll, ll> >());
        for (auto e : add[i]) {
            upg.pb(mp((frac){e.first, a[i]}, e.second));
            a[i] += e.first;
        }
    }

    sort(upg.begin(), upg.end());
    while (upg.size() > 0 && k > 0) {
        k--;
        sol.pb(upg.back().second);
        upg.pop_back();
    }

    sort(sol.begin(), sol.end(), [](const int a, const int b)->bool{
        return tp[a] < tp[b];
    });

    printf("%d\n", sol.size());
    for (auto e : sol)
        printf("%d ", e);



    return 0;
}