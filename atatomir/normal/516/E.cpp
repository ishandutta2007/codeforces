#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>
#include <map>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300011

ll n, m, cnt, i, x, y, d;
vector<ll> boys, girls;
vector< pair<ll, ll> > data;
ll ans;

ll dist[maxN];
vector< pair<ll, ll> > list[maxN];
priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > H;
map<ll, ll> M;

void no_sol() {
    printf("-1");
    exit(0);
}

ll euclid(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }

    ll xx, yy;
    ll d = euclid(b, a % b, xx, yy);
    x = yy;
    y = xx - (a / b) * yy;
    return d;
}

ll sub_solve(vector< pair<ll, ll> >& pos, ll total, ll jump) {
    ll i, p;

    p = 1;
    sort(pos.begin(), pos.end());

    for (i = 1; i < pos.size(); i++)
        if (pos[p - 1].first != pos[i].first)
            pos[p++] = pos[i];
    pos.resize(p);

    for (i = 0; i <= pos.size(); i++) list[i].clear(), dist[i] = 1LL << 60;
    for (i = 1; i <= pos.size(); i++) list[0].pb(mp(i, pos[i - 1].second));
    for (i = 2; i <= pos.size(); i++) {
        list[i - 1].pb(mp(i,  jump * (pos[i - 1].first - pos[i - 2].first) ));
        assert(list[i - 1].back().second >= 0);
    }
    list[pos.size()].pb(mp(1, jump * (pos[0].first + total - pos.back().first)));
    assert(list[pos.size()].back().second >= 0);

    while (!H.empty()) H.pop();
    H.push(mp(0, 0));
    dist[0] = 0;

    while (!H.empty()) {
        auto act = H.top(); H.pop();
        if (dist[act.second] != act.first) continue;

        for (auto to : list[act.second]) {
            if (dist[to.first] > dist[act.second] + to.second) {
                dist[to.first] = dist[act.second] + to.second;
                H.push(mp(dist[to.first], to.first));
            }
        }
    }

    ll ans = 0;
    for (i = 1; i <= pos.size(); i++) {
        if (M[dist[i]] == 1)
            M[dist[i]] = 0;
        else
            ans = max(ans, dist[i]);
    }
    for (i = 1; i < pos.size(); i++)
        if (pos[i].first - pos[i - 1].first > 1)
            ans = max(ans, dist[i] + jump * (pos[i].first - pos[i - 1].first - 1));

    if (pos[0].first + total - pos.back().first - 1 > 0)
        ans = max(ans, dist[pos.size()] + jump * (pos[0].first + total - pos.back().first - 1));

    return ans;
}

ll solve(ll jump, ll mod) {
    ll i, j, k, bonus, a, b, c, x, y;
    ll done = 0;
    ll ans = 0;
    vector< pair<ll, ll> > aux;

    sort(data.begin(), data.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b)->bool const {
        return a.first % d < b.first % d;
    });

    for (i = 0; i < data.size(); i = j) {
        for (j = i; j < data.size(); j++)
            if (data[i].first % d != data[j].first % d)
                break;

        done++;
        aux.clear();
        bonus = data[i].first % d;

        for (k = i; k < j; k++) {
            a = jump;
            b = mod;
            c = (mod + data[k].first - bonus) % mod;

            euclid(a, b, x, y);
            x *= c / d;
            y *= c / d;

            x %= mod;
            x = (x + mod) % mod;
            x %= mod / d;
            aux.pb(mp(x, data[k].second));
        }

        ans = max(ans, sub_solve(aux, mod / d, jump));
    }

    if (done != d) no_sol();
    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &m);

    scanf("%lld", &cnt);
    boys = vector<ll>(cnt);
    for (auto& e : boys) scanf("%lld", &e);

    scanf("%lld", &cnt);
    girls = vector<ll>(cnt);
    for (auto& e : girls) scanf("%lld", &e);

    d = euclid(n, m, x, y);
    if (d > 100000) no_sol();

    data.clear(); M.clear();
    for (auto e : boys) data.pb(mp(e, e)), M[e] = 1;
    for (auto e : girls) data.pb(mp(e % n, e));
    ans = solve(m, n);

    data.clear(); M.clear();
    for (auto e : girls) data.pb(mp(e, e)), M[e] = 1;
    for (auto e : boys) data.pb(mp(e % m, e));
    ans = max(ans, solve(n, m));

    printf("%lld", ans);

    return 0;
}