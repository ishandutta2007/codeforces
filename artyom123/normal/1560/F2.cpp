#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define ll long long 
#define ld long double
#define int ll 

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

int count_dig(int x) {
    set<int> s;
    while (x) {
        s.insert(x % 10);
        x /= 10;
    }
    return (int)s.size();
}

int solve(int n, int k) {
    int ans = 2 * INF;
    if (count_dig(n) <= k) return n;
    vector<int> d;
    int n1 = n;
    while (n1) {
        d.pb(n1 % 10);
        n1 /= 10;
    }
    reverse(all(d));
    int cnt_diff = 0;
    vector<int> cnt(10);
    for (int i = 0; i < (int)d.size(); i++) {
        for (int x = d[i] + 1; x < 10; x++) {
            cnt[x]++;
            if (cnt[x] == 1) cnt_diff++;
            if (cnt_diff <= k) {
                if (i == (int)d.size() - 1) {
                    int now = 0;
                    for (int j = 0; j < i; j++) {
                        now *= 10;
                        now += d[j];
                    }
                    now *= 10;
                    now += x;
                    ans = min(ans, now);
                } else {
                    int y = 0;
                    while (cnt[y] == 0) y++;
                    if (k > cnt_diff || cnt[0]) y = 0;
                    int now = 0;
                    for (int j = 0; j < i; j++) {
                        now *= 10;
                        now += d[j];
                    }
                    now *= 10;
                    now += x;
                    for (int j = i + 1; j < (int)d.size(); j++) {
                        now *= 10;
                        now += y;
                    }
                    ans = min(ans, now);
                    //cout << '!' << " " << now << " " << i << " " << x << endl;
                }
            }
            cnt[x]--;
            if (cnt[x] == 0) cnt_diff--;
        }
        cnt[d[i]]++;
        if (cnt[d[i]] == 1) cnt_diff++;
    }
    return ans;
}

signed main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}