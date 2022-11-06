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

#define maxN 100011

int n, i, x, xoro;
int a[maxN];
vector<int> list[maxN];
int tp[maxN];
vector<int> one, zero;
map<int, int> M;

ll ans;


void dfs(int node) {
    tp[node] = 1;

    for (auto to : list[node]) {
        dfs(to);
        tp[node] = tp[to] ^ 1;
    }

    if (tp[node] == 0)
        zero.pb(a[node]);
    else
        one.pb(a[node]);
}

ll comb2(ll x) {
    return (1LL * x * (x - 1)) / 2LL;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 2; i <= n; i++) {
        cin >> x;
        list[x].pb(i);
    }

    dfs(1);
    for (auto e : one) xoro ^= e;
    for (auto e : zero) M[e]++;

    if (xoro != 0) ans += comb2(one.size()) + comb2(zero.size());
    for (auto e : one) {
        int aux = xoro ^ e;
        ans += 1LL * zero.size() - M[aux];
    }

    ans = comb2(n) - ans;
    cout << ans;

    return 0;
}