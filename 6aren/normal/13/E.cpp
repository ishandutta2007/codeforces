#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//Naive Solution as follows...

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

const int N = 100005;
const int BL = 450;

int a[N], r[N], nxt[N], cnt[N];
int b[N], la[N];

void run_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i], b[i] = a[i] + i;
    for (int i = 0; i < n; i++) r[i] = min(n - 1, i / BL * BL + BL - 1);
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] >= r[i]) cnt[i] = 1, nxt[i] = b[i], la[i] = i;
        else {
            cnt[i] = cnt[b[i]] + 1;
            nxt[i] = nxt[b[i]];
            la[i] = la[b[i]];
        }
    }

    auto query = [&](int id) {
        int cur = id;
        int res = 0, last = 0;
        while (cur < n) {
            res += cnt[cur];
            last = la[cur];
            cur = nxt[cur];
        }
        cout << last + 1 << ' ' << res << '\n';
    };

    while (m--) {
        int type;
        cin >> type;
        if (type == 0) {
            int x, y;
            cin >> x >> y;
            x--;
            a[x] = y;
            b[x] = x + y;
            int l = x / BL * BL;
            for (int i = x; i >= l; i--) {
                if (b[i] >= r[i]) cnt[i] = 1, nxt[i] = b[i], la[i] = i;
                else {
                    cnt[i] = cnt[b[i]] + 1;
                    nxt[i] = nxt[b[i]];
                    la[i] = la[b[i]];
                }
            }
        } else {
            int id;
            cin >> id;
            query(id - 1);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    while (tests--) run_case();
    return 0;
}