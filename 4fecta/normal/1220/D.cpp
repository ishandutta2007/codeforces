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

int n, b[MN];
vector<int> cnt2[70];

int32_t main() {
    boost();

    cin >> n;
    vector<int> e, o;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        int tmp = b[i], cnt = 0;
        while (tmp % 2 == 0) tmp /= 2, cnt++;
        cnt2[cnt].push_back(b[i]);
    }
    int mx = 0, id = -1;
    for (int i = 0; i < 70; i++) {
        if (cnt2[i].size() > mx) {
            mx = cnt2[i].size();
            id = i;
        }
    }
    vector<int> out;
    for (int i = 0; i < 70; i++) {
        if (i == id) continue;
        for (int p : cnt2[i]) out.push_back(p);
    }
    cout << out.size() << "\n";
    for (int p : out) cout << p << " ";

    return 0;
}