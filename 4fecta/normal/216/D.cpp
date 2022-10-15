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
 
const int MN = 1005;
 
int n, k, u, ans = 0;
ordered_set a[MN];
vector<int> v[MN];
 
int main() {
    boost();
 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> u;
            a[i].insert(u);
            v[i].push_back(u);
        }
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 1; i <= n; i++) {
        int l = i - 1, r = i + 1;
        if (l < 1) l = n;
        if (r > n) r = 1;
        //printf("sz:%d\n", v[i].size());
        for (int j = 1; j < v[i].size(); j++) {
            int c1 = a[l].order_of_key(v[i][j]) - a[l].order_of_key(v[i][j - 1]);
            int c2 = a[r].order_of_key(v[i][j]) - a[r].order_of_key(v[i][j - 1]);
            if (c1 != c2) {
                ans++;
                //printf("%d %d %d %d\n", i, j, c1, c2);
            }
        }
    }
    printf("%d\n", ans);
 
    return 0;
}