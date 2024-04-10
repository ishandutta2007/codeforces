#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int mod2 = (int) 1308570269;
const int inf = (1<<30) - 1;
ll st1[maxn];
ll st2[maxn];
ll sum1[maxn];
ll sum2[maxn];
struct Hash{
    ll a, b;
    int len;
    Hash() {
        len = 0;
        a = 0;
        b = 0;
    }
    Hash merge(Hash o) {
        Hash nw;
        nw.a = (a + o.a * st1[len]) % mod;
        nw.b = (b + o.b * st2[len]) % mod2;
        nw.len = len + o.len;
        return nw;
    }
    void upd(int x) {
        a = sum1[len-1] * x % mod;
        b = sum2[len-1] * x % mod2;
    }
} t[maxn * 4];
int n;
int val[4 * maxn];
void push(int v, int l, int r) {
    if(l == r || val[v] == -1) return;
    val[v * 2] = val[v];
    val[v * 2 + 1] = val[v];
    t[v*2].upd(val[v]);
    t[v * 2 + 1].upd(val[v]);
    val[v] = -1;
}
string s;
void build(int v, int l, int r) {
    val[v] = -1;
    if(l == r) {
        t[v].len=1;
        t[v].a = s[l] - '0';
        t[v].b = s[l] - '0';
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v*2+1, mid+1, r);
        t[v] = t[v*2].merge(t[v*2 + 1] );
    }
}

Hash get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if(tl > r || l > tr) return {};
    if(l <= tl && tr <= r) {
        return t[v];
    }
    int mid = (tl + tr)/2;
    return get(v * 2, tl, mid, l, r).merge(get(v * 2+1, mid + 1, tr, l, r));
}
void upd(int v, int tl, int tr, int l, int r, int x) {
    push(v, tl, tr);
    if(tl > r || l > tr) return;
    if(l <= tl && tr <= r) {
        val[v] = x;
        t[v].upd(x);
        return;
    }
    int mid = (tl + tr)/2;
    upd(v * 2, tl, mid, l, r, x);
    upd(v * 2 + 1, mid + 1, tr, l, r, x);
    t[v] = t[v * 2].merge(t[v*2+1]);
}


void solve() {
    int m, k;
    cin >> n >> m >> k >> s;
    st1[0] = 1;
    st2[0] = 1;
    sum1[0] = 1;
    sum2[0] = 1;
    for(int i = 1; i < maxn; i++) {
        st1[i] = st1[i-1] * 31 % mod;
        st2[i] = st2[i-1] * 37 % mod2;
        sum1[i] = (sum1[i-1] + st1[i]) % mod;
        sum2[i] = (sum2[i-1] + st2[i]) % mod2;
    }
    m += k;
    build(1, 0, n-1);
    for(int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r, c;
            cin >> l >> r >> c;
            upd(1, 0, n-1, l-1, r-1, c);
        } else {
            int l, r, d;
            cin >> l >> r >> d;
            l--;
            r--;
            Hash a = get(1, 0, n-1, l+d, r);
            Hash b = get(1, 0, n-1, l, r-d);
            if(a.a == b.a && a.b == b.b) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
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