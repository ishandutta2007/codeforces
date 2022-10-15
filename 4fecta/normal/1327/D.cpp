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

int n, p[MN], c[MN], vis[MN], ans;
vector<int> v;

void dfs(int cur) {
    vis[cur] = 1; v.push_back(c[cur]);
    if (!vis[p[cur]]) dfs(p[cur]);
}

bool check(int d) {
    bool ret = 0;
    for (int i = 0; i < d; i++) {
        bool meme = 1;
        for (int j = i; j < v.size(); j += d) if (v[j] != v[i]) {meme = 0; break;}
        ret |= meme;
    }
    return ret;
}

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = n;
        for (int i = 1; i <= n; i++) vis[i] = 0;
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            v.clear();
            dfs(i);
//        for (int p : v) printf("%d ", p);
//        printf("\n");
            for (int i = 1; i <= v.size(); i++) {
                if (v.size() % i) continue;
                if (check(i)) ans = min(ans, i);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}