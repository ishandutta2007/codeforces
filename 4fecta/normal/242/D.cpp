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

const int MN = 100005;

int n, m, u, v, val[MN], used[MN];
pii req[MN];
vector<int> a[MN];

void push(int idx) {
    val[idx]++;
    for (int nxt : a[idx]) val[nxt]++;
}

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> req[i].f, req[i].s = i;
    sort(req + 1, req + n + 1);
    vector<int> ans;
    int cnt = 0;
    for (int t = 0; t < 100; t++) {
        for (int i = 1; i <= n; i++) {
            //if (req[i].f > val[req[i].s]) break;
            if (req[i].f == val[req[i].s]) {
                push(req[i].s), ans.push_back(req[i].s), cnt++;
                if (used[req[i].s]) return 0 * printf("-1");
                used[req[i].s] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            //if (req[i].f > val[req[i].s]) break;
            if (req[i].f == val[req[i].s]) {
                push(req[i].s), ans.push_back(req[i].s), cnt++;
                if (used[req[i].s]) return 0 * printf("-1");
                used[req[i].s] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            //if (req[i].f > val[req[i].s]) break;
            if (req[i].f == val[req[i].s]) {
                push(req[i].s), ans.push_back(req[i].s), cnt++;
                if (used[req[i].s]) return 0 * printf("-1");
                used[req[i].s] = 1;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i : ans) printf("%d ", i);

    return 0;
}