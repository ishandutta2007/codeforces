#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

struct q {
    int t, s, p, id;
    bool x;
    q(int a, int b, int c, int d, bool kek) {
        t = a, s = b, p = c, id = d, x = kek;
    }
    q() {}
};

bool operator < (const q &a, const q &b) {
    return mp(a.t, a.p) < mp(b.t, b.p);
}

multiset <int> cur;

struct cc {
    bool operator()(const q &a, const q &b) const {
        return a.p < b.p;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    vector <q> r(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &r[i].t, &r[i].s, &r[i].p);
        r[i].id = i;
        r[i].x = (r[i].p == -1);
        if (r[i].p == -1) {
            x = i;
        }
        cur.insert(r[i].p);
    }
    set <int> d;
    for (int i = 0; i < n; i++) {
        if (r[i].p == -1) continue;
        if (!cur.count(r[i].p - 1) && r[i].p > 1) {
            d.insert(r[i].p - 1);
        }
        if (!cur.count(r[i].p + 1) && r[i].p < (int) 1e9) {
            d.insert(r[i].p + 1);
        }
    }
    vector <int> f;
    for (auto x : d) {
        f.pb(x);
    }
    int t = d.size();
    ll T;
    scanf("%lld", &T);
    int vl = -1, vr = t - 1;
    while (vl < vr - 1) {
        int vm = (vl + vr) / 2;
        int x = f[vm];
        for (int i = 0; i < n; i++) {
            if (r[i].x) {
                r[i].p = x;
            }
        }
        sort(all(r));
        multiset <q, cc> t;
        ll ans = 0, prev = 0;
        vector <ll> res(n);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                ll was = r[i].t - prev;
                while (t.size() > 0 && was != 0) {
                    q h = *(--t.end());
                    t.erase(--t.end());
                    if (h.s > was) {
                        h.s -= was;
                        was = 0;
                        t.insert(h);
                    } else {
                        was -= h.s;
                        res[h.id] = r[i].t - was;
                        if (h.x) ans = res[h.id];
                    }
                }
            }
            t.insert(r[i]);
            prev = r[i].t;
        }
        while (!t.empty()) {
            q h = *(--t.end());
            t.erase(--t.end());
            prev += h.s;
            res[h.id] = prev;
            if (h.x) ans = prev;
        }
        if (ans <= T) {
            vr = vm;
        } else {
            vl = vm;
        }
    }
    ll ans = 0, prev = 0;
    vector <ll> res(n);
    {
        int vm = vr;
        int x = f[vm];
        for (int i = 0; i < n; i++) {
            if (r[i].x) {
                r[i].p = x;
            }
        }
        sort(all(r));
        multiset <q, cc> t;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                ll was = r[i].t - prev;
                while (t.size() > 0 && was != 0) {
                    q h = *(--t.end());
                    t.erase(--t.end());
                    if (h.s > was) {
                        h.s -= was;
                        was = 0;
                        t.insert(h);
                    } else {
                        was -= h.s;
                        res[h.id] = r[i].t - was;
                        if (h.x) ans = res[h.id];
                    }
                }
            }
            t.insert(r[i]);
            prev = r[i].t;
        }
        while (!t.empty()) {
            q h = *(--t.end());
            t.erase(--t.end());
            prev += h.s;
            res[h.id] = prev;
            if (h.x) ans = prev;
        }
    }
    printf("%d\n", f[vr]);
    for (int i = 0; i < n; i++) {
        printf("%lld ", res[i]);
    }
    puts("");
}