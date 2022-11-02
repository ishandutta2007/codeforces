#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
int a[6];
int b[maxn];
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 6; ++i)
        cin >> a[i];
    sort(a, a + 6);
    cin >> n;
    vector<int> kek(6 * n);
    int p = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        for (int j = 0; j < 6; ++j) {
            kek[p] = b[i] - a[j];
            ++p;
        }
    }
    sort(b, b + n);
    uniq(kek);
    vector<int> pt(6, 0);
    int ans = 1e18;
    for (int i = 0; i < (int)kek.size(); ++i) {
        int cur_len = kek[i];
        for (int j = 0; j < 6; ++j) {
            while (pt[j] < n && b[pt[j]] - a[j] < cur_len)
                ++pt[j];
        }
        if (pt[0] != 0)
            continue;
        int cur_ans = 0;
        for (int j = 0; j < 6; ++j) {
            int pos;
            if (j == 5)
                pos = n - 1;
            else
                pos = pt[j + 1] - 1;
            if (pos < pt[j])
                continue;
            cur_ans = max(cur_ans, b[pos] - a[j] - cur_len);
        }
        //cout << cur_len << " " << cur_ans << "\n";
        ans = min(ans, cur_ans);
    }
    cout << ans;
}