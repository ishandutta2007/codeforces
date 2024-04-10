#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

typedef long long ll;

using namespace std;    

struct Car {
    ll c;
    ll v;
};

bool operator < (const Car &a, const Car &b) {
    return a.v < b.v;
}

const ll INF = 1e10;

int main() {
    ios_base::sync_with_stdio(0);

    int n, k;
    ll s, t;
    cin >> n >> k >> s >> t;

    vector<Car> cars(n);
    for (int i = 0; i < n; ++i)
        cin >> cars[i].c >> cars[i].v;

    sort(all(cars));

    vector<ll> g(k);
    for (int i = 0; i < k; ++i)
        cin >> g[i];
    g.push_back(0);
    g.push_back(s);
    sort(all(g));

    // for (int i = 0; i < k; ++i)
    //     cout << g[i] << " ";
    // cout << endl;

    vector<ll> l(k + 1);

    for (int i = 0; i <= k; ++i)
        l[i] = g[i + 1] - g[i];
    sort(all(l));

    // for (int i = 0; i < sz(l); ++i)
    //     cout << l[i] << " ";
    // cout << endl;

    vector<ll> pref(k + 2);
    pref[0] = 0;
    for (int i = 0; i <= k; ++i)
        pref[i + 1] = pref[i] + l[i];

    // cout << endl;

    ll ans = INF;
    for (int i = 0; i < n; ++i) {
        if (l[k] > cars[i].v)
            continue;

        int lf = 0, rg = k + 1;
        while (rg - lf > 1) {
            int mid = (lf + rg) / 2;
            if (l[mid] > cars[i].v / 2)
                rg = mid;
            else 
                lf = mid;
        }

        // cout << cars[i].v << " " << rg << endl;

        ll curT = pref[rg];

        curT += 3ll * (pref[k + 1] - pref[rg]) - (ll)(k - rg + 1) * cars[i].v;

        // cout << curT << endl;

        if (curT <= t)
            ans = min(ans, cars[i].c);
    }

    if (ans == INF)
        cout << -1 << endl;
    else 
        cout << ans << endl;

    return 0;
}