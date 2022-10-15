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

const int MN = 105;

int n, a[MN], vis[MN], o = 0, e = 0;

int main() {
    boost();

    cin >> n;

    int ans = 0;
    int prev = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
        if (a[i]) {
            cnt++;
            if (prev) {
                if (prev % 2 == a[i] % 2) ans += 2;
                else ans++;
            }
            prev = a[i];
        }
    }
    if (n == 1) return 0 * printf("0\n");
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (i % 2) o++;
            else e++;
        }
    }
    vector<int> eg, og;
    prev = 0;
    int pid = 0;
    int ep = -1, es = -1,  op = -1, os = -1, idx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            idx = i;
            if (prev) {
                if (prev % 2 == a[i] % 2) {
                    if (prev % 2) og.push_back(i - pid - 1);
                    else eg.push_back(i - pid - 1);
                }
            } else {
                if (a[i] % 2) op = i - 1;
                else ep = i - 1;
                ans++;
            }
            prev = a[i];
            pid = i;
        }
    }
    if (idx) {
        if (prev % 2) os = n - idx;
        else es = n - idx;
        ans++;
    }
    sort(og.begin(), og.end());
    sort(eg.begin(), eg.end());
    int oidx = 0, eidx = 0;
    while (oidx < og.size()) {
        if (og[oidx] <= o) {
            o -= og[oidx++];
            ans -= 2;
        } else break;
    }
    while (eidx < eg.size()) {
        if (eg[eidx] <= e) {
            e -= eg[eidx++];
            ans -= 2;
        } else break;
    }
    if (op >= 0 && op <= o) o -= op, ans--;
    if (os >= 0 && os <= o) o -= os, ans--;
    if (ep >= 0 && ep <= e) e -= ep, ans--;
    if (es >= 0 && es <= e) e -= es, ans--;
    if (!ans) ans++;
    printf("%d\n", ans);

    return 0;
}