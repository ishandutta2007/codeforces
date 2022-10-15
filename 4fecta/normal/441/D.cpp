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

const int MN = 3005;

int n, m, k, a[MN], vis[MN], pos[MN];

bool proc(int x) {
    vis[x] = 1;
    while (!vis[a[x]]) x = a[x], vis[x] = 1;
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    m = n - m;
    for (int i = 1; i <= n; i++) if (!vis[i]) k++, proc(i);
    memset(vis, 0, sizeof(vis));
    printf("%d\n", abs(k - m));
    if (k > m) { //break
        proc(1);
        for (int i = 2; i <= n; i++) {
            if (vis[i]) continue;
            k--, proc(i);
            printf("1 %d ", i);
            if (k == m) break;
        }
    }
    if (k < m) { //join
        for (int i = 1; i <= n; i++) {
            memset(pos, -1, sizeof(pos));
            int id = 1;
            for (int j = a[i]; j != i; j = a[j]) {
                pos[j] = id++;
            }
            pos[i] = id;
            id = 1;
            for (int j = i + 1; j <= n; j++) {
                if (pos[j] >= id) {
                    k++;
                    id = pos[j] + 1;
                    swap(a[i], a[j]);
                    printf("%d %d ", i, j);
                    if (k == m) return 0;
                }
            }
        }
    }


    return 0;
}