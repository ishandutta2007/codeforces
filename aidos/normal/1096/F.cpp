#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int a[maxn];
int n;
int t_f[maxn];
int u[maxn];
int get(int pos) {
    int res = 0;

    while(pos >= 0) {
        res += t_f[pos];
        pos = (pos & (pos+1)) - 1;
    }
    return res;
}
void add(int pos, int val) {
    while(pos <= n) {
        t_f[pos] += val;
        pos |= pos + 1;
    }
}
ll t[4*maxn];
ll S[4*maxn];
ll val[4*maxn];
void build(int v, int l, int r) {
    val[v] = 0;
    t[v] = 0;
    if(l == r) {
        S[v] = 1-u[l];
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        S[v] = S[v * 2] + S[v*2+1];
    }
}
void push(int v, int l,int r) {
    if(l == r || val[v] == 0) return;
    t[v*2] = (t[v * 2] + val[v] * S[v * 2]) % mod;
    t[v*2 + 1] = (t[v * 2 + 1] + val[v] * S[v * 2 + 1]) % mod;
    val[v * 2] += val[v];
    val[v * 2 + 1] += val[v];
    val[v] = 0;
}
void add(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if(tl > r || l > tr) return;
    if(l <= tl && tr <= r) {
        val[v]++;
        t[v] = (t[v] + S[v]) % mod;
        return;
    }
    int mid = (tl + tr)/2;
    add(v * 2, tl, mid, l, r);
    add(v * 2 + 1, mid + 1, tr, l, r);
    t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;
}
ll binpow(ll x, ll y) {
    if(y == 0) return 1;
    if(y % 2 == 1) return binpow(x, y-1) * x % mod;
    return binpow(x * x % mod, y/2);
}
void solve() {
    cin >> n;
    ll cur = 0;
    ll F = 1;
    ll S = 1;
    ll T = 1;
    ll cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] > 0) {
            u[a[i]] = 1;
            cur += get(n) - get(a[i]);
            add(a[i], 1);
        } else {
            cnt++;
            F = F * cnt % mod;
        }
    }
    cur %= mod;
    if(cnt == 0) {
        cout << cur << "\n";
        return;
    }
    if(cnt == 1) {
        int pos = 1;
        while(u[pos] == 1) pos++;
        memset(t_f, 0, sizeof t_f);
        cur = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] == -1) a[i] = pos;
            if(a[i] > 0) {
                cur += get(n) - get(a[i]);
                add(a[i], 1);
            } else {
                cnt++;
                F = F * cnt % mod;
            }
        }
        cout << cur % mod << "\n";
        return;
    }
    for(int i = 1; i <= cnt - 2; i++) {
        S = S * i % mod;
    }
    T = S * (cnt - 1) % mod;
    build(1, 1, n);
    ll A = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == -1) {
            A = (A + t[1]) % mod;
        } else {
            add(1, 1, n, 1,a[i] - 1);
        }
    }
    build(1, 1, n);
    for(int i = n; i >= 1;i--) {
        if(a[i] == -1) {
            A = (A + t[1]) % mod;
        } else {
            add(1, 1, n, a[i] + 1, n);
        }
    }
    ll Q = binpow(F, mod-2);
    //cout << cur * F % mod << "\n";
    //cout << A * T % mod << "\n";
    //cout << (((F * cnt) % mod *(cnt-1)) % mod) * binpow(4, mod-2) % mod << "\n";
    ll P = (cur * F % mod + A * T + (((F * cnt) % mod *(cnt-1)) % mod) * binpow(4, mod-2) % mod) % mod;
    cout << P * Q % mod << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}