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

int n; ll ans;
vector<int> v;
string s;
map<int, int> mp;

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int open = 0, closed = 0;
        for (char c : s) {
            if (c == ')') {
                if (open > 0) open--;
                else closed++;
            } else open++;
        }
        if (open && closed) continue;
        v.push_back(open - closed);
    }
    for (int p : v) {
        ans += mp[-p];
        if (!p) ans += mp[-p] + 1;
        mp[p]++;
    }
    printf("%lld\n", ans);

    return 0;
}