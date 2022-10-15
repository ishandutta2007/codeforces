#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int dist(pii p1, pii p2) {
    return abs(p1.f - p2.f) + abs(p1.s - p2.s);
}

bool cmp1(pii x, pii y) {
    if (x.f != y.f) return x.f < y.f;
    return x.s > y.s;
}

bool cmp2(pii x, pii y) {
    if (x.s != y.s) return x.s < y.s;
    return x.f > y.f;
}

int n, x, y;
map<int, vector<pii>> mp;
map<int, vector<int>> dp;
map<int, pii> lft, rit;
vector<int> v;

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        mp[max(x, y)].push_back({x, y});
        v.push_back(max(x, y));
    }
    mp[0].push_back({0, 0});
    v.push_back(0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    dp[0].resize(2);
    dp[0][0] = dp[0][1] = 0;
    lft[0] = rit[0] = {0, 0};
    int c = 0, p = 0;
    for (int i = 1; i < v.size(); i++) {
        c = v[i], p = v[i - 1];
        dp[c].resize(2);
        sort(mp[c].begin(), mp[c].end(), cmp1);
        lft[c] = mp[c][0];
        sort(mp[c].begin(), mp[c].end(), cmp2);
        rit[c] = mp[c][0];
        int ex = dist(lft[c], rit[c]);
        dp[c][0] = min(dp[p][0] + dist(lft[p], rit[c]), dp[p][1] + dist(rit[p], rit[c])) + ex;
        dp[c][1] = min(dp[p][0] + dist(lft[p], lft[c]), dp[p][1] + dist(rit[p], lft[c])) + ex;
    }
    printf("%lld\n", min(dp[c][0], dp[c][1]));

    return 0;
}