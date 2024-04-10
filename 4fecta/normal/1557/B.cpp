// Problem: B. Moamen and k-subarrays
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n,k, a[100005];
        cin >>  n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int l = 1;
        vector<pii> v;
        for (int i = 1; i <= n; i++) v.push_back({a[i], i});
        sort(v.begin(), v.end());
        int cnt = 1;
        for (int i = 1; i < n; i++) if (v[i].s != v[i - 1].s + 1) cnt++;
        bool ok = cnt <= k;

        if (ok) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}