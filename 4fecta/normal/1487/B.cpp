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

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 0) {
            printf("%d\n", (k - 1) % n + 1);
        } else {
            int freq = n / 2;
            int cnt = (k - 1) / freq;
            printf("%d\n", (k - 1 + cnt) % n + 1);
        }
    }


    return 0;
}