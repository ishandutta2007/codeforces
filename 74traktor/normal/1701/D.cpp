#include<bits/stdc++.h>

using namespace std;

int const maxn = 5e5 + 5;
int b[maxn], l[maxn], r[maxn], a[maxn], sz[maxn];

struct pt {
    int pos, t, i, when;
};

int getR(int i, int x, int n) {
    int lef = 1, righ = n + 1;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (i / mid >= x) lef = mid;
        else righ = mid;
    }
    return lef;
}

int getL(int i, int x, int n) {
    int lef = 0, righ = n + 1;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (i / mid > x) lef = mid;
        else righ = mid;
    }
    return righ;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        vector < pt > Q;
        for (int i = 1; i <= n; i++) {
            l[i] = getL(i, b[i], n), r[i] = getR(i, b[i], n);
            Q.push_back({l[i], 0, i, r[i]});
            Q.push_back({r[i] + 1, 1, i, r[i]});
        }
        sort(Q.begin(), Q.end(), [](pt s, pt f) {
            return s.pos < f.pos;
        });
        set < pair < int, int > > pos;
        int ptr = 0;
        for (int v = 1; v <= n; v++) {
            while (ptr < (int)Q.size() && Q[ptr].pos == v) {
                if (Q[ptr].t == 0) pos.insert({Q[ptr].when, Q[ptr].i});
                else pos.erase({Q[ptr].when, Q[ptr].i});
                ptr++;
            }
            a[(*pos.begin()).second] = v;
            pos.erase(pos.begin());
        }
        for (int i = 1; i <= n; i++) {
            assert(i / a[i] == b[i]);
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}