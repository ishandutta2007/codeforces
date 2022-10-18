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

const ll INF = 9e18;
int bit[100055], n;

void modify(int x, int v) {
    for (++x; x <= n + 1; x += x & -x)
        bit[x] += v;
}

int query(int x) {
    int rt = 0;
    for (++x; x; x -= x & -x)
        rt += bit[x];
    return rt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll ans = INF;
        string s, t, srt;
        cin >> n >> s >> t;
        srt = s;
        sort(ALL(srt));
        fill(bit, bit + n + 10, 0);
        if (srt >= t) {
            cout << "-1\n";
            continue;
        }
        vector<int> pl[26];
        for (int i = n - 1; i >= 0; --i)
            pl[int(s[i] - 'a')].pb(i);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < int(t[i] - 'a'); ++j)
                if (!pl[j].empty()) {
                    int rp = query(pl[j].back()) + pl[j].back();
                    ans = min(ans, sum + rp - i); 
                }
            if (pl[int(t[i] - 'a')].empty())
                break;
            int p = pl[int(t[i] - 'a')].back();
            pl[int(t[i] - 'a')].pop_back();
            sum += query(p) + p - i;
            modify(0, 1), modify(p, -1);
        }
        cout << ans << "\n";
    }
}