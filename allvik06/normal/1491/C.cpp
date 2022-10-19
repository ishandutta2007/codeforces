#include <bits/stdc++.h>

using namespace std;
#define int long long

inline int get_next1(int i, vector <int>& now) {
    int l = i - 1, r = now.size() - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (now[mid + 1] > now[i]) r = mid;
        else l = mid;
    }
    return r;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> s(n);
        for (int i = 0; i < n; ++i) cin >> s[i];
        int ans = 0;
        vector <int> now(n + 1);
        vector <bool> cha(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] > 1) cha[i] = true;
        }
        for (int i = 0; i < n; ++i) {
            now[i + 1] = now[i] + cha[i];
        }
        for (int i = 0; i < n; ++i) {
            if (i + s[i] >= n) {
                int ne = max(1LL, n - i - 1LL);
                ans += s[i] - ne;
                s[i] = ne;
                if (s[i] == 1 && cha[i]) {
                    for (int j = 0; j < n; ++j) {
                        now[j + 1] = now[j] + (s[j] > 1);
                    }
                    cha[i] = false;
                }
            }
            while (s[i] > 1) {
                ++ans;
                int cur = i;
                while (cur < n) {
                    int next1 = cur + s[cur];
                    s[cur] = max(s[cur] - 1, 1LL);
                    if (s[cur] == 1 && now[cur]) {
                        for (int j = 0; j < n; ++j) {
                            now[j + 1] = now[j] + cha[j];
                        }
                        cha[cur] = false;
                    }
                    cur = get_next1(next1, now);
                }
            }
        }
        cout << ans << "\n";
    }
}