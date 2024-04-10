#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

vector<vector<int>> edge;
vector<int> vis;

const int P = 1e9 + 7;

pair<long long, long long> dfs(int v) {
    if (vis[v] == 2)
        return make_pair((long long)0, (long long)1);
    vis[v] = 1;
    vector<pair<long long, long long>> a;
    for (int i = 0; i < sz(edge[v]); ++i)
        if (vis[edge[v][i]] != 1)
            a.push_back(dfs(edge[v][i]));
    if (!sz(a))
        return make_pair((long long)1, (long long)0);

    vector<long long> pref(sz(a)), suff(sz(a));
    pref[0] = 1;
    for (int i = 1; i < sz(a); ++i)
        pref[i] = (pref[i - 1] * (a[i - 1].first + a[i - 1].second)) % P;
    suff[sz(a) - 1] = 1;
    for (int i = sz(a) - 2; i >= 0; --i)
        suff[i] = (suff[i + 1] * (a[i + 1].first + a[i + 1].second)) % P;

    long long ans1 = (pref[sz(a) - 1] * (a[sz(a) - 1].first + a[sz(a) - 1].second)) % P;
    long long ans2 = 0;
    for (int i = 0; i < sz(a); ++i) {
        ans2 += ((pref[i] * suff[i]) % P) * a[i].second % P;
        ans2 %= P;
    }

    return make_pair(ans1, ans2);
}

int main() {
    int n;
    cin >> n;
    edge.resize(n);
    vis.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u;
        cin >> u;
        edge[u].push_back(i + 1);
        edge[i + 1].push_back(u);
    }
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        if (x[i])
            vis[i] = 2;
    }
    long long ans = 1;
    for (int i = 0; i < n; ++i)
        if (vis[i] == 0) {
            ans *= dfs(i).second;
            ans %= P;
        }

    cout << ans << endl;

}