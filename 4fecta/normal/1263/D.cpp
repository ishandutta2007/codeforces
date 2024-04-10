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

const int MN = 200005;

int n, par[MN];
string a[MN];
bool use[26];
bool ids[MN];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    par[x] = par[y];
    return true;
}

int main() {
    boost();

    for (int i = 1; i < MN; i++) par[i] = i;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < a[i].size(); j++) {
            use[a[i][j] - 'a'] = 1;
        }
        for (int j = 0; j < a[i].size(); j++) {
            for (int k = j + 1; k < a[i].size(); k++) {
                merge(a[i][j] - 'a', a[i][k] - 'a');
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (use[i]) ids[find(i)] = 1;
    }

    int ans = 0;
    for (int i = 0; i < MN; i++) ans += ids[i];

    printf("%d\n", ans);

    return 0;
}