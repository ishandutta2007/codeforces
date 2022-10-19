#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <map>
#include <algorithm>

using namespace std;
#define int long long
const int INF = 1e10;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector <int> maxx(n, -1);
    for (int i = 0; i < n; ++i) {
        maxx[a[i]] = i;
    }
    int ans = 0, now = -1, prev_now;
    while (now < n) {
        prev_now = now;
        ++now;
        int cnt = 0, len = 1;
        while (now < n) {
            ++cnt;
            int new_now = now;
            for (int i = prev_now + 1; i <= now; ++i) new_now = max(new_now, maxx[a[i]]);
            len += new_now - now;
            if (new_now == now) {
                now = new_now;
                break;
            }
            prev_now = now;
            now = new_now;
        }
        --cnt;
        if (len <= 2) {
            continue;
        }
        ans += len - cnt - 1;
    }
    cout << ans;
}

/*

 */