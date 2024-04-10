#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
int n, m;
struct query{
    int type;
    int x1, y1, x2, y2;
    ll v;
} Q[maxn];

struct fenwick {
    ll a[1010][1010];
    void clear() {
        memset(a, 0, sizeof a);
    }
    ll get(int x, int y) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i+1)) - 1) {
            for(int j = y; j >= 0; j = (j&(j+1)) - 1) {
                res ^= a[i][j];
            }
        }
        return res;
    }
    void update(int x, int y, ll c){
        for(int i = x; i <= n; i |= i+1) {
            for(int j = y; j <= n; j |= j+1) {
                a[i][j] ^= c;
            }
        }
    }

    ll get(int x1, int y1, int x2, int y2) {
        return get(x2, y2)^get(x1-1, y2)^get(x2, y1-1)^get(x1-1, y1-1);
    }
} F[2][2];
ll get(int x1, int y1) {
    return F[x1 % 2][y1 % 2].get(x1, y1);
}
ll get(int x1, int y1, int x2, int y2) {
    return get(x2, y2)^get(x1-1, y2)^get(x2, y1-1)^get(x1-1, y1-1);
}

void update(int x1, int y1, ll c) {
    F[x1 % 2][y1 % 2].update(x1, y1, c);
}
void updateRange(int x1, int y1, int x2, int y2, ll c) {
    update(x1, y1, c);
    update(x2+1, y1, c);
    update(x1, y2 + 1, c);
    update(x2 + 1, y2 + 1, c);
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int type, x1, y1, x2, y2;
        cin >> type >> x1 >> y1 >> x2 >> y2;
        if(type == 2) {
            ll v;
            cin >> v;
            updateRange(x1, y1, x2, y2, v);
        } else {
            cout << get(x1, y1, x2, y2) << "\n";
        }
    }

};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}