#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int K = 100;
vector<int> pool[300005], value, edge[300005];

int arr[300005], cnt[300005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        vector<int> allp;
        ll ans = 0;
        cin >> n >> m;
        value.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i], value.pb(arr[i]);
            pool[i].clear();
        }
        sort(ALL(value)), value.resize(unique(ALL(value)) - value.begin());
        fill(cnt, cnt + SZ(value), 0);
        for (int i = 1; i <= n; ++i) {
            arr[i] = lower_bound(ALL(value), arr[i]) - value.begin();
            ++cnt[arr[i]];
        }
        for (int i = 0; i < SZ(value); ++i) {
            pool[cnt[i]].pb(i);
            edge[i].clear();
            edge[i].pb(i);
        }
        for (int i = 1; i <= m; ++i) {
            int a, b;
            cin >> a >> b;
            a = lower_bound(ALL(value), a) - value.begin();
            b = lower_bound(ALL(value), b) - value.begin();
            edge[a].pb(b);
            edge[b].pb(a);
        }
        for (int i = 0; i < SZ(value); ++i) {
            sort(ALL(edge[i]));
            if (cnt[i] > K)
                allp.pb(i); 
        }
        for (int i = 0; i < SZ(value); ++i)
            for (int j = 1; j <= K; ++j) {
                int nwa = SZ(pool[j]) - 1;
                int nwb = SZ(edge[i]) - 1;
                while (nwa >= 0 && nwb >= 0) {
                    while (nwb >= 0 && pool[j][nwa] < edge[i][nwb])
                        --nwb;
                    if (nwb >= 0 && pool[j][nwa] != edge[i][nwb]) {
                        ans = max(ans, (ll)(cnt[i] + j) * (value[i] + value[pool[j][nwa]]));
                        break;
                    }
                    else
                        --nwa, --nwb;
                }
            }
        for (int i = 0; i < SZ(allp); ++i)
            for (int j = i + 1; j < SZ(allp); ++j) {
                auto p = lower_bound(ALL(edge[allp[i]]), allp[j]);
                if (p == edge[allp[i]].end() || *p != allp[j])
                    ans = max(ans, (ll)(cnt[allp[i]] + cnt[allp[j]]) * (value[allp[i]] + value[allp[j]]));
            } 
        cout << ans << "\n";
    }
}