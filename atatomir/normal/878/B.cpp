#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300011

ll n, k, m, i;
ll a[maxN], aux;

ll ini_size, sz2;
deque< pair<ll, ll> > Q;
vector< pair<ll, ll> > ini;

void add_to_que(ll val, ll cnt) {
    cnt %= k;
    if (cnt == 0) return;

    if (Q.empty()) {
        Q.push_back(mp(val, cnt));
    } else {
        if (Q.back().first == val) {
            auto last = Q.back(); Q.pop_back();
            last.second = (last.second + cnt) % k;
            if (last.second != 0) Q.push_back(last);
        } else {
            Q.push_back(mp(val, cnt));
        }
    }
}

void solve() {
    int i, dif;

    dif = 0;
    while (Q.size() > 1) {
        auto frs = Q.front();
        auto last = Q.back();

        if (frs.first != last.first)
            break;

        dif += frs.second;

        Q.pop_front();
        Q.pop_back();
        last.second = (frs.second + last.second) % k;
        if (last.second != 0)
            Q.push_back(last);
    }

    if (Q.empty()) {
        printf("%lld\n", ini_size);
        exit(0);
    }

    if (Q.size() > 1) {
        sz2 = 0;

        while (!Q.empty()) {
            sz2 += Q.back().second;
            Q.pop_back();
        }

        printf("%lld\n", ini_size + (m - 1) * sz2);
        exit(0);
    }

    auto rez = Q.back();
    Q.pop_back();
    rez.second = (rez.second * (m - 1)) % k;

    if (rez.second == 0) {
        printf("%lld", ini_size);
        exit(0);
    }

    for (i = 0; i < ini.size() && dif > 0; i++) {
        add_to_que(ini[i].first, ini[i].second);
        dif -= ini[i].second;
    }

    add_to_que(rez.first, rez.second);

    for (; i < ini.size(); i++) {
        add_to_que(ini[i].first, ini[i].second);
    }

    ini_size = 0;
    while (!Q.empty())  {
        ini_size += Q.back().second;
        Q.pop_back();
    }

    printf("%lld", ini_size);
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &k, &m);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        add_to_que(a[i], 1);
    }

    while (!Q.empty()) {
        ini.pb(Q.front());
        Q.pop_front();
        ini_size += ini.back().second;
    }

    for (auto e : ini)
        Q.push_back(e);

    if (Q.empty()) {
        printf("0");
        return 0;
    }

    if (Q.size() == 1) {
        aux = Q.back().second;
        aux *= m;
        aux %= k;

        printf("%lld", aux);
        return 0;
    }

    solve();



    return 0;
}