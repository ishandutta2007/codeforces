#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 50005;

int t, n, a[MN], psa[MN], x;

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += 100001;
            psa[i] = a[i] + psa[i - 1];
        }
        cin >> x;
        x += 100001;
        int cnt = 0;
        int l = 1;
        vector<pii> hull;
        for (int i = 1; i <= n; i++) {
            bool bad = 0;
            /*for (int j = l; j < i; j++) if ((psa[i] - psa[j - 1]) < x * (i - j + 1)) bad = 1;
            if (!bad) cnt++;
            else l = i + 1;*/

            pii cur = {i, psa[i]};
            int lo = 0, hi = hull.size() - 1, mid;
            while (lo < hi) {
                mid = (lo + hi) / 2;
                if ((cur.s - hull[mid].s) * (cur.f - hull[mid+1].f) > (cur.s - hull[mid+1].s) * (cur.f - hull[mid].f)) lo = mid + 1;
                else hi = mid;
            }
            if (hull.size() && (cur.s - hull[lo].s) < x * (cur.f - hull[lo].f)) bad = 1;
            if (!bad) {
                cnt++;
                cur = {i - 1, psa[i - 1]};
                while (hull.size() > 1 && (cur.s - hull.back().s) * (hull.back().f - hull[hull.size() - 2].f) >= (hull.back().s - hull[hull.size() - 2].s) * (cur.f - hull.back().f)) hull.pop_back();
                hull.push_back(cur);
            } else hull.clear();
        }
        printf("%lld\n", cnt);
    }

    return 0;
}