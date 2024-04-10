#include <bits/stdc++.h>

using namespace std;

struct pt {
    int x, y, z;
};

int used[50005];
int inf = 3e8;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector < pair < pt, int > > a;
    int x, y, z, n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y >> z;
        a.push_back({{x, y, z}, i});
    }
    sort(a.begin(), a.end(), [](pair < pt, int > c, pair < pt, int > d) {
         if (c.first.x != d.first.x) return c.first.x < d.first.x;
         if (c.first.y != d.first.y) return c.first.y < d.first.y;
         return c.first.z < d.first.z;
    });
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        int j = i, cnt = 0;
        while (j < n && a[i].first.x == a[j].first.x) {
            if (used[j] == 0) cnt++;
            ++j;
        }
        if (cnt > 1) {
            vector < pair < pt, int > > f;
            vector < int > in;
            j = i;
            while (j < n && a[i].first.x == a[j].first.x) {
                if (used[j] == 0) {
                    f.push_back(a[j]);
                    in.push_back(j);
                }
                ++j;
            }
            for (int z = 0; z < (int)f.size(); ++z) {
                if (used[in[z]]) continue;
                if (z != (int)f.size() - 1 && f[z].first.y == f[z + 1].first.y) {
                    used[in[z]] = 1, used[in[z + 1]] = 1;
                    cout << f[z].second << " " << f[z + 1].second << '\n';
                }
            }
            int ptr = 0;
            for (int z = 0; z < (int)f.size(); ++z) {
                if (used[in[z]]) continue;
                ptr = max(ptr, z + 1);
                while (ptr < (int)f.size() && used[in[ptr]]) ptr++;
                if (ptr != (int)f.size()) {
                    used[in[ptr]] = 1;
                    used[in[z]] = 1;
                    cout << f[z].second << " " << f[ptr].second << '\n';
                }
            }
        }
    }
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        ptr = max(ptr, i + 1);
        while (ptr < n && used[ptr]) ptr++;
        cout << a[i].second << " " << a[ptr].second << '\n';
        used[i] = 1, used[ptr] = 1;
    }
    return 0;
}