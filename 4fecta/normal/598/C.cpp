#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define double ld
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const double PI = atan(1) * 4;

vector<pair<double, int>> v;
int n;
double x, y;

bool cmp(pair<double, int> x, pair<double, int> y) {
    return x.f < y.f;
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        double ang = atan2(y, x) * 180 / PI;
        v.push_back({ang, i});
        v.push_back({ang + 360, i});
        v.push_back({ang - 360, i});
    }
    sort(v.begin(), v.end(), cmp);
    double mi = 360;
    pii ans = {0, 0};
    for (int i = 1; i < v.size(); i++) {
        if (v[i].f - v[i - 1].f < mi) {
            mi = v[i].f - v[i - 1].f;
            ans = {v[i].s, v[i - 1].s};
        }
    }
    printf("%d %d\n", ans.f, ans.s);

    return 0;
}