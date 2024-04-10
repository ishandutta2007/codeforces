// NOT MY CODE

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;


const int N = 2e5 + 100, M = 1e6 + 100, K = 450;

int a[N], cnt[M];
long long po = 0;

inline void del(int i) {
    int x = a[i];
    int cn = cnt[x];
    po += (-x * cn * cn + x * (cn - 1) * (cn - 1));
    cnt[x]--;
}

inline void add(int i) {
    int x = a[i];
    int cn = cnt[x];
    po += (x * (cn + 1) * (cn + 1) - x * cn * cn);
    cnt[x]++;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector <array <int, 3>> seg(q);
    for (int i = 0; i < q; i++) {
        cin >> seg[i][0] >> seg[i][1];
        seg[i][0]--, seg[i][1]--;
        seg[i][2] = i;
    }
    sort(seg.begin(), seg.end(), [](const array <int, 3>& a, const array <int, 3>& b) {
        return pair <int, int> {a[0] / K, a[1]} < pair <int, int> {b[0] / K, b[1]};
    });

    vector <long long> ans(q);
    int l = 0, r = -1;
    for (auto [L, R, seg_number] : seg) {
        while (R > r)
            add(++r);

        while (L < l)
            add(--l);

        while (R < r)
            del(r--);

        while (L > l)
            del(l++);

        ans[seg_number] = po;
    }

    for (auto i : ans)
        cout << i << "\n";
    return 0;
}