#include <bits/stdc++.h>

using namespace std;
int k = 475;
struct trio {
    int len, l, r;
};

bool cmp(trio a, trio b) {
    if (a.l / k == b.l / k) return a.r < b.r;
    return a.l < b.l;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        vector <trio> z;
        int maxx = 0;
        for (int i = 0; i < 200; ++i) {
            vector <int> now;
            for (int j = 0; j < n; ++j) {
                if (a[j] == i) {
                    now.push_back(j);
                }
            }
            maxx = max(maxx, (int)now.size());
            int l = 0, r = (int)now.size() - 1;
            while (r > l) {
                if (now[l] + 1 > now[r] - 1) {
                    maxx = max(maxx, 2 * (l + 1));
                }
                z.push_back({2 * (l + 1), now[l] + 1, now[r] - 1});
                ++l;
                --r;
            }
        }
        vector <int> cha(200);
        vector <trio> zz;
        for (trio i : z) {
            if (i.l / k == i.r / k) {
                int ma = 0;
                for (int j = i.l; j <= i.r; ++j) {
                    ++cha[a[j]];
                    if (cha[a[j]] > ma) ma = cha[a[j]];
                }
                cha.assign(200, 0);
                maxx = max(i.len + ma, maxx);
            }
            else {
                zz.push_back(i);
            }
        }
        sort(zz.begin(), zz.end(), cmp);
        int ch = 0;
        for (int _ = k; _ < n; _ += k) {
            if (ch == zz.size()) break;
            if (zz[ch].l / k != _ / k - 1) continue;
            vector <int> now(200);
            int ma = 0;
            for (int j = _; j < n; ++j) {
                ++now[a[j]];
                ma = max(ma, now[a[j]]);
                while (ch < zz.size() && zz[ch].l / k == _ / k - 1 && zz[ch].r == j) {
                    int tmp = ma;
                    for (int i = zz[ch].l; i < _; ++i) {
                        ++now[a[i]];
                        tmp = max(tmp, now[a[i]]);
                    }
                    maxx = max(maxx, tmp + zz[ch].len);
                    for (int i = zz[ch].l; i < _; ++i) {
                        --now[a[i]];
                    }
                    ++ch;
                }
            }
        }
        cout << maxx << "\n";
    }
}