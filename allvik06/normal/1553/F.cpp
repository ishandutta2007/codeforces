#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;
#define int long long
const int MAXC = 3e5 + 10;

struct Fen1 {
    vector <int> f;

    Fen1() {
        f.resize(MAXC);
    }

    inline void add(int i, int x) {
        for (++i; i < MAXC; i += (i & (-i))) f[i] += x;
    }

    inline int get_pref(int i) {
        int ans = 0;
        for (i = min(i + 1, MAXC - 1); i > 0; i -= (i & (-i))) ans += f[i];
        return ans;
    }

    inline int get_seg(int l, int r) {
        return get_pref(r) - get_pref(l - 1);
    }
};

struct Fen2 {
    vector <int> f;

    Fen2() {
        f.resize(MAXC);
    }

    inline int get_point(int i) {
        int ans = 0;
        for (++i; i < MAXC; i += (i & (-i))) ans += f[i];
        return ans;
    }

    inline void add_pref(int i, int x) {
        for (i = min(i + 1, MAXC - 1); i > 0; i -= (i & (-i))) f[i] += x;
    }

    inline void add_seg(int l, int r, int x) {
        add_pref(r, x);
        add_pref(l - 1, -x);
    }
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <int> a(n), p(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Fen1 sum1, cnt1;
    Fen2 sum2, cnt2;
    for (int i = 0; i < n; ++i) {
        if (i > 0) p[i] = p[i - 1];
        p[i] += cnt2.get_point(a[i]) * a[i] + sum2.get_point(a[i]);
        p[i] += sum1.get_pref(a[i]);
        for (int lvl = 1; a[i] * lvl < MAXC; ++lvl) {
            p[i] += sum1.get_seg(a[i] * lvl, a[i] * (lvl + 1) - 1) - cnt1.get_seg(a[i] * lvl, a[i] * (lvl + 1) - 1) * a[i] * lvl;
            sum2.add_seg(a[i] * lvl, a[i] * (lvl + 1) - 1, -a[i] * lvl);
            cnt2.add_seg(a[i] * lvl, a[i] * (lvl + 1) - 1, 1);
        }
        cnt2.add_seg(1, a[i] - 1, 1);
        sum1.add(a[i], a[i]);
        cnt1.add(a[i], 1);
        cout << p[i] << " ";
    }
}