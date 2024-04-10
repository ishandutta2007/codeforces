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

const int MN = 500005;

int n;
vector<int> ans;

int main() {
    boost();

    cin >> n;
    for (int i = 2; i <= n; i++) {
        int mx = 1;
        for (int j = 2; j * j <= n; j++) {
            if (i % j == 0) mx = max(mx, i / j);
        }
        ans.push_back(mx);
    }
    sort(ans.begin(), ans.end());
    for (int num : ans) printf("%d ", num);

    return 0;
}