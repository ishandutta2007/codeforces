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

const vector<ll> pre = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

int n, i, x;
map< pair<int, ll> , ll> M;

ll solve(ll x, ll conf) {
    vector<int> sg = {};

    if (M[mp(x, conf)]) return M[mp(x, conf)];
    for (int i = 1; i <= x; i++) {
        if (conf & (1LL << i)) continue;
        sg.pb(solve(x - i, conf | (1LL << i)));
    }

    sort(sg.begin(), sg.end());

    if (sg.empty()) {
        M[mp(x, conf)] = 0;
        return 0;
    }

    if (sg[0] != 0) {
        M[mp(x, conf)] = 0;
        return 0;
    }

    for (int i = 1; i < sg.size(); i++) {
        if (sg[i - 1] + 1 < sg[i]) {
            M[mp(x, conf)] = sg[i - 1] + 1;
            return sg[i - 1] + 1;
        }
    }

    M[mp(x, conf)] = sg.back() + 1;
    return sg.back() + 1;
}

int main()
{
    //freopen("test.in","r",stdin);
    /*freopen("test.out", "w", stdout);

    printf("{");
    for (i = 1; i <= 60; i++) {
        cerr << i << '\n';
        printf("%lld, ", solve(i, 0));
    }*/

    //cerr << pre.size();

    scanf("%d", &n);
    ll ans = 0;

    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        ans ^= pre[x - 1];
    }

    if (ans == 0)
        printf("YES\n");
    else
        printf("NO\n");



    return 0;
}