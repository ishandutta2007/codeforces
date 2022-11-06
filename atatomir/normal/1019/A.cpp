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

const int maxN = 3011;

ll n, m, i, x, y;
vector<ll> v[maxN], aux;
ll sol = 1LL << 60;

void check(int limit) {
    ll i, j, win = 0;
    ll ans = 0;

    win = v[1].size();
    aux.clear();

    for (i = 2; i <= m; i++) {
        for (j = 0; j < limit && j < v[i].size(); j++) aux.pb(v[i][j]);

        for (j = limit; j < v[i].size(); j++) {
            ans += v[i][j];
            win++;
        }
    }

    sort(aux.begin(), aux.end());
    for (auto e : aux) {
        if (win > limit) break;
        win++;
        ans += e;
    }

    sol = min(sol, ans);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> x >> y;
        v[x].pb(y);
    }

    for (i = 1; i <= m; i++) {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
    }

    for (i = 0; i < n; i++) check(i);
    cout << sol;


    return 0;
}