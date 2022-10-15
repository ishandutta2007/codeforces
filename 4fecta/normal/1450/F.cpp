#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>
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

const int MN = 100005;

int t, n, a[MN], freq[MN], f[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) freq[i] = f[i] = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], freq[a[i]]++;
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) continue;
            if ((n + 1) / freq[i] <= 1) ok = 0;
        }
        if (!ok) {printf("-1\n"); continue;}
        a[n + 1] = a[n];
        int l = 1;
        vector<pii> v;
        deque<pii> v1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[i + 1]) {
                v.push_back({a[l], a[i]});
                l = i + 1;
            }
        }
        for (int i = 1; i <= n; i++) freq[i] = 0;
        int gap = 1, ans = v.size() - 1;
        sort(v.begin(), v.end());
        for (pii p : v) {
            if (p.f != p.s) freq[p.f]++, freq[p.s]++, gap++;
            else f[p.f]++;
        }
        priority_queue<pii> pq;
        for (int i = 1; i <= n; i++) {
            if (f[i] > 0) pq.push({f[i] + freq[i], i});
        }
        while (pq.size() > 1) {
            pii p1 = pq.top(); pq.pop();
            pii p2 = pq.top(); pq.pop();
            freq[p1.s]++, freq[p2.s]++, gap++;
            f[p1.s]--, f[p2.s]--;
            if (f[p1.s] > 0) pq.push({f[p1.s] + freq[p1.s], p1.s});
            if (f[p2.s] > 0) pq.push({f[p2.s] + freq[p2.s], p2.s});
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < f[i]; j++) v1.push_back({i, i});
        }
        shuffle(v1.begin(), v1.end(), std::mt19937(std::random_device()()));
        for (pii p : v1) {
            if (gap <= freq[p.f]) ans++, freq[p.f]--;
            gap++, freq[p.f] += 2;
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++) freq[i] = f[i] = 0;
    }

    return 0;
}