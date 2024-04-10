#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int n, a[MN], b[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int ev = 0, od = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] %= 2;
            if (a[i]) od++;
            else ev++;
        }
        if (abs(ev - od) > 1) {printf("-1\n"); continue;}
        int ans = 1e12;
        if (ev >= od) {
            int tmp = 0;
            vector<int> id1, id2;
            for (int i = 1; i <= n; i++) if (a[i]) id1.push_back(i);
            for (int i = 2; i <= n; i += 2) id2.push_back(i);
            assert(id1.size() == id2.size());
            for (int i = 0; i < id1.size(); i++) tmp += abs(id1[i] - id2[i]);
            ans = min(ans, tmp);
        }
        if (od >= ev) {
            int tmp = 0;
            vector<int> id1, id2;
            for (int i = 1; i <= n; i++) if (a[i]) id1.push_back(i);
            for (int i = 1; i <= n; i += 2) id2.push_back(i);
            assert(id1.size() == id2.size());
            for (int i = 0; i < id1.size(); i++) tmp += abs(id1[i] - id2[i]);
            ans = min(ans, tmp);
        }
        printf("%lld\n", ans);
    }

    return 0;
}