#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, m;
vector<pii> v;

int main() {
    boost();

    cin >> n >> m;
    pii p = {0, m};
    while (1) {
        if (p.f > n || p.s < 0) break;
        v.push_back(p);
        p = {p.f + 1, p.s - 1};
    }
    cout << v.size() << "\n";
    for (pii p : v) cout << p.f << " " << p.s << "\n";

    return 0;
}