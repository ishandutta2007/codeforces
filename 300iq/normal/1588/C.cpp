#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 3e5 + 20;


ll t[2][4 * N];

void build(int id, int v, int l, int r, vector <ll> &arr) {
    if (r - l == 1) {
        t[id][v] = arr[l];
    } else {
        int m = (l + r) / 2;
        build(id, v * 2 + 1, l, m, arr);
        build(id, v * 2 + 2, m, r, arr);
        t[id][v] = min(t[id][v * 2 + 1], t[id][v * 2 + 2]);
    }
}

const ll inf = 1e18;

ll get(int id, int v, int l, int r, int tl, int tr) {
    if (tl >= r || tr <= l) return inf;
    if (tl >= l && tr <= r) return t[id][v];
    else {
        int tm = (tl + tr) / 2;
        return min(get(id, v * 2 + 1, l, r, tl, tm), get(id, v * 2 + 2, l, r, tm, tr));
    }
}

map <ll, int> last[2][2];

ll smart(vector <int> a) {
    int n = (int) a.size();
    ll ans = 0;
    vector <ll> p(n);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        p[i] = x - (i ? p[i - 1] : 0);
    }
    auto a_1 = p;
    auto a_2 = p;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) a_1[i] = inf;
        if (i % 2 == 1) a_2[i] = inf;
    }
    build(0, 0, 0, n, a_1);
    build(1, 0, 0, n, a_2);
    vector <int> jmp(n);
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) last[i][j].clear();
    for (int i = n - 1; i >= 0; i--) {
        last[i % 2][0][p[i]] = i;
        last[i % 2][1][-p[i]] = i;
        ll x = (i ? p[i - 1] : 0);
        int me = n + 2;
        if (last[(i + 1) % 2][0].count(x)) {
            me = min(me, last[(i + 1) % 2][0][x]);
        }
        if (last[i % 2][1].count(x)) {
            me = min(me, last[i % 2][1][x]);
        }
        if (me == n + 2) jmp[i] = -2;
        else jmp[i] = me;
    }
    vector <int> ret(n + 1);
    auto check = [&] (int l, int r) {
        ll x = (l ? p[l - 1] : 0);
        return get((l)% 2, 0, l, r + 1, 0, n) >= x && get((l+1) % 2, 0, l, r + 1, 0, n) >= -x;
    };
    for (int l = n - 1; l >= 0; l--) {
        int r = jmp[l] + 1;
        if (r == -1) continue;
        if (check(l, r - 1)) {
            ret[l] = ret[r] + 1;
        } else {
            ret[l] = 0;
        }
        ans += ret[l];
    }

    return ans;
}

ll naive(vector <int> a) {
    int n = (int) a.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = i; j < n; j++) {
            x = a[j] - x;
            if (x < 0) break;
            if (x == 0) ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    while (true) {
        int n = rnd() % 4 + 1;
        vector <int> a(n);
        for (int i = 0; i < n; i++) a[i] = rnd() % 10;
        if (smart(a) != naive(a)) {
            cout << n << endl;
            for (int x : a) cout << x << ' ';
            cout << endl;
            cout << smart(a) << ' ' << naive(a) << endl;
            return 0;
        } else {
            cout << "OK" << endl;
        }
    }
*/
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << smart(a) << '\n';
    }
}