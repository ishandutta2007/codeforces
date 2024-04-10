#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, a[MN], lft[MN], rit[MN], ans;

void proc(vector<pii> v) {
    if (v.empty()) return;
    int l = v[0].f, r = v.back().s;
    ans += r - l - 1;
    int cnt = 0, cov = 0;
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1 || v[i + 1].f > cov) cov = v[i].s, cnt++;
    }
    ans -= cnt - 1;
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!lft[a[i]]) lft[a[i]] = i;
        rit[a[i]] = i;
    }
    vector<pii> v, w;
    for (int i = 1; i <= n; i++) {
        if (lft[i] == rit[i]) continue;
        v.push_back({lft[i], rit[i]});
    }
    sort(v.begin(), v.end());
    int mx = 0;
    for (pii p : v) {
        if (p.s > mx) mx = p.s, w.push_back(p);
    }
    v = w;
    mx = 0;
    w.clear();
    for (pii p : v) {
        //printf("%lld %lld\n", p.f, p.s);
        if (p.f < mx) {
            mx = p.s;
            w.push_back(p);
        } else {
            mx = p.s;
            proc(w);
            w.clear();
            w.push_back(p);
        }
    }
    proc(w);
    printf("%lld\n", ans);

    return 0;
}