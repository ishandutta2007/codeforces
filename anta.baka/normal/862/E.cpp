#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;

int n, m, q, b[100000];
set<ll> B;
ll a, sum;

ll get() {
    if(B.find(a) != B.end()) return 0;
    auto it = B.insert(a).first;
    ll ret = INF;
    auto nxt = it;
    nxt++;
    if(nxt != B.end()) {
        ret = *nxt - a;
    }
    if(it != B.begin()) {
        auto pr = it;
        pr--;
        ret = min(ret, a - *pr);
    }
    B.erase(it);
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i % 2 == 0) a += x;
        else a -= x;
    }
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < n; i++) if(i & 1) sum -= b[i]; else sum += b[i];
    for(int i = 0; i <= m - n; i++) {
        B.insert(sum);
        sum -= b[i];
        sum = -sum;
        if(i + n != m) {
            if(n % 2) sum += b[i + n];
            else sum -= b[i + n];
        }
    }
    cout << get() << '\n';
    for(int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        --l; --r;
        if((r - l + 1) % 2 != 0) {
            if(l % 2 == 0) a += x;
            else a -= x;
        }
        cout << get() << '\n';
    }
}