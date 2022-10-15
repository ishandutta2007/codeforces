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

const int MN = 300005;

int n, a[MN];
ll ans = 0;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (pq.size() && pq.top() < a[i]) {
            ans += a[i] - pq.top();
            pq.pop();
            pq.push(a[i]);
        }
        pq.push(a[i]);
    }
    printf("%lld\n", ans);

    return 0;
}