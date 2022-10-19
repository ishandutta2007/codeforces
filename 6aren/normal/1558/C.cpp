#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename A> ostream& operator<<(ostream &os, const vector<A> &vt) {
    os << '[';
    for (size_t i = 0; i + 1 < vt.size(); i++) os << vt[i] << ", ";
    if (!vt.empty()) os << vt.back();
    return os << ']';
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef GAREN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void run_case() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 != i % 2) ok = false;
    }
    if (!ok) {
        cout << -1 << '\n';
        return;
    }

    vector<int> res;

    auto do_ope = [&](int k) {
        res.push_back(k);
        reverse(a.begin() + 1, a.begin() + k + 1);
    };

    int cur = n - 1;
    while (cur != 0) {
        int pos[2];
        auto find_pos = [&]() {
            for (int i = 0; i < 2; i++) {
                for (int j = 1; j <= n; j++) {
                    if (a[j] == cur + i) pos[i] = j;
                }
            }
        };
        find_pos();
        if (pos[0] == cur + 0 && pos[1] == cur + 1) {
            cur -= 2;
            continue;
        }
        do_ope(pos[1]);
        // dbg(a);
        find_pos();
        do_ope(pos[0] - 1);
        // dbg(a);
        find_pos();
        do_ope(pos[0] + 1);
        // dbg(a);
        find_pos();
        do_ope(pos[1]);
        // dbg(a);
        do_ope(cur + 1);
        find_pos();
        // dbg(res);
        // dbg(a);
        assert(pos[0] == cur && pos[1] == cur + 1);
        cur -= 2;
    }
    assert(res.size() <= 5 * n / 2);
    // for (int i = 1; i <= n; i++) assert(a[i] == i);
    cout << res.size() << '\n';
    for (int e : res) cout << e << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    cin >> tests;
    while (tests--) run_case();
    return 0;
}