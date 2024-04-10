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

int n, k; char a[MN];

int main() {
    boost();

    cin >> n >> k;
    if (k == n) {
        cout << "tokitsukaze";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cleft = 0, crigh = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            cleft = i;
            break;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] != a[i + 1]) {
            crigh = i;
            break;
        }
    }
    if (cleft == 0) {
        cout << "tokitsukaze";
        return 0;
    }
    if (a[1] == a[n]) {
        if (crigh - cleft + 1 <= k) {
            cout << "tokitsukaze";
            return 0;
        } else {
            cout << "once again";
            return 0;
        }
    } else {
        if (crigh <= k || n - cleft + 1 <= k) {
            cout << "tokitsukaze";
            return 0;
        } else if (crigh == k + 1 && n - cleft + 1 == k + 1 && (n - crigh < k && cleft - 1 < k)) {
            cout << "quailty";
            return 0;
        } else {
            cout << "once again";
            return 0;
        }
    }


    return 0;
}