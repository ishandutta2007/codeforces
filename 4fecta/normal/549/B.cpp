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

const int MN = 705;

int n, a[MN], has[MN];
vector<int> ans;
string s[MN];

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (1) {
        int pos = -1;
        for (int i = 1; i <= n; i++) if (a[i] == has[i]) pos = i;
        if (pos == -1) break;
        ans.push_back(pos);
        for (int i = 1; i <= n; i++) if (s[pos][i - 1] == '1') has[i]++;
    }
    cout << ans.size() << "\n";
    for (int p : ans) cout << p << " ";

    return 0;
}