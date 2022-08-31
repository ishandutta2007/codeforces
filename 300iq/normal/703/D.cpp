#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

const int N = (int) 1e6 + 7;
int t[4 * N];
int a[N];
int pref[N];
int ans[N];
map <int, int> last;

void upd(int v, int l, int r, int i, int x) {
    if (r - l == 1) {
        t[v] = a[i] = x;
    } else {
        int m = (l + r) / 2;
        if (i < m) upd(v * 2 + 1, l, m, i, x);
        else upd(v * 2 + 2, m, r, i, x);
        t[v] = t[v * 2 + 1] ^ t[v * 2 + 2];
    }
}

int get(int v, int l, int r, int tl, int tr) {
    if (r <= tl || tr <= l) 
        return 0;
    if (l <= tl && tr <= r) {
        return t[v];
    } else {
        int tm = (tl + tr) / 2;
        return get(v * 2 + 1, l, r, tl, tm) ^ get(v * 2 + 2, l, r, tm, tr);
    }

}

struct event {
    int type, l, r, ind;
    event(int a, int b, int c, int d) {
        type = a;
        l = b;
        r = c;
        ind = d;
    }
    event() {}
};

bool operator < (event a, event b) {
    if (a.r != b.r) return a.r < b.r;
    else return a.type < b.type;
}

vector <event> e;

int get(int l, int r) {
    if (l) return pref[r] ^ pref[l - 1];
    else return pref[r];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        e.pb({-1, a[i], i, i});
    }
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] ^ a[i]; 
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        e.pb({1, l, r, i});
    }
    sort(all(e));
    for (auto c : e) {
        if (c.type == -1) {
            if (last.count(c.l)) upd(0, 0, n, last[c.l], 0);
            last[c.l] = c.r;
            upd(0, 0, n, last[c.l], c.l);
        } else {
            ans[c.ind] = get(c.l, c.r) ^ get(0, c.l, c.r + 1, 0, n);
        }
    }
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
}