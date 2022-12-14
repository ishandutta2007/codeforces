#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 3e5 + 10;
const int MOD = 1e9 + 7;
const int T = 50;

int a[MAXN];

ll fen[T][MAXN];

void add(int idx, ll val, int t) {
    for (; idx < MAXN; idx += idx & -idx)
        fen[t][idx] += val;
}

ll get(int idx, int t) {
    ll ret = 0;
    for (; idx; idx -= idx & -idx)
        ret += fen[t][idx];
    return ret;
}

ll get(int l, int r, int t) {
    return get(r, t) - get(l - 1, t);
}

int pw2[MAXN], pw3[MAXN];

ll rdm(int x, int y) {
    return (y * pw2[x] % MOD) + (y * pw3[x]); 
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    pw2[0] = pw3[0] = 1;
    for (int i = 1; i < T; i++) {
        pw2[i] = 2LL * pw2[i - 1] % MOD;
        pw3[i] = 3LL * pw3[i - 1] % MOD;
    }
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < T; j++) {
            add(i, rdm(j, a[i]), j);
        }
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, x;
            cin >> idx >> x;
            for (int j = 0; j < T; j++) {
                add(idx, rdm(j, x) - rdm(j, a[idx]), j);
            }
            a[idx] = x;
        }
        else {
            int l, r, k;
            cin >> l >> r >> k;
            bool correct = 1;
            for (int j = 0; j < T; j++) {
                ll sum = get(l, r, j);
                if (sum % k != 0) {
                    correct = 0;
                    break;
                }
            }
            cout << (correct ? "YES\n" : "NO\n");
        }
    }
}