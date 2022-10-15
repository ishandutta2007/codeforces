#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int t, n, m, a[MN], bad[MN], dp[2], ndp[2];
pii seg[MN];

int32_t main() {
    boost();
a[0]=-1e15;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        n++;
        a[n] = 1e12;
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= m; i++) cin >> seg[i].f >> seg[i].s, bad[i] = 0;
        sort(seg + 1, seg + m + 1);
        priority_queue<pii> q;
        for (int i = 1; i <= m; i++) {
            while (q.size() && q.top().f >= seg[i].s) bad[q.top().s] = 1, q.pop();
            q.push({seg[i].s, i});
        }
        vector<pii> v;
        for (int i = 1; i <= m; i++) if (!bad[i]) v.push_back(seg[i]);
        for (int i = 1; i < v.size(); i++) assert(v[i - 1].f <= v[i].f && v[i - 1].s <= v[i].s);
        int id = 0;
        dp[0] = 0; //previous point no longer moves
        dp[1] = 1e12; //previous point can move to the right
        for (int i = 1; i <= n; i++) {
            vector<pii> segs;
            while (id < v.size() && v[id].s < a[i]) segs.push_back(v[id++]);
            while (id < v.size() && v[id].f <= a[i]) id++;
            //segments in segs is now strictly btw a[i-1] and a[i]
            if (segs.empty()) {
                int best = min(dp[0], dp[1]);
                dp[0] = dp[1] = best;
                continue;
            }

            int mn = 1e12;
            for (int j = 0; j <= segs.size(); j++) {
                if (j == 0) mn = min(mn, abs(a[i] - segs[j].s));
                else if (j == segs.size()) mn = min(mn, (abs(segs[j - 1].f - a[i - 1])) * 2);
                else mn = min(mn, (abs(segs[j - 1].f - a[i - 1])) * 2 + abs(a[i] - segs[j].s));
            }
            ndp[0] = dp[0] + mn;

            mn = 1e12;
            for (int j = 0; j <= segs.size(); j++) {
                if (j == 0) mn = min(mn, abs(a[i] - segs[j].s));
                else if (j == segs.size()) mn = min(mn, abs(segs[j - 1].f - a[i - 1]));
                else mn = min(mn, abs(segs[j - 1].f - a[i - 1]) + abs(a[i] - segs[j].s));
            }
            ndp[0] = min(ndp[0], dp[1] + mn);

            mn = 1e12;
            for (int j = 0; j <= segs.size(); j++) {
                if (j == 0) mn = min(mn, (abs(a[i] - segs[j].s)) * 2);
                else if (j == segs.size()) mn = min(mn, (abs(segs[j - 1].f - a[i - 1])) * 2);
                else mn = min(mn, (abs(segs[j - 1].f - a[i - 1])) * 2 + (abs(a[i] - segs[j].s)) * 2);
            }
            ndp[1] = dp[0] + mn;

            mn = 1e12;
            for (int j = 0; j <= segs.size(); j++) {
                if (j == 0) mn = min(mn, (abs(a[i] - segs[j].s)) * 2);
                else if (j == segs.size()) mn = min(mn, abs(segs[j - 1].f - a[i - 1]));
                else mn = min(mn, abs(segs[j - 1].f - a[i - 1]) + (abs(a[i] - segs[j].s)) * 2);
            }
            ndp[1] = min(ndp[1], dp[1] + mn);

            dp[0] = ndp[0], dp[1] = ndp[1];
            //printf("%lld %lld\n", dp[0], dp[1]);
        }
        printf("%lld\n", min(dp[0], dp[1]));
    }

    return 0;
}