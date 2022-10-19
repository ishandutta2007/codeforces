#ifndef LOCAL
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

//#define int ll
#ifndef LOCAL
//#define endl '\n'
#endif

#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

mt19937 rd(time(NULL));

vector<int> MODS = {998244353, (int) 1e9 + 7, (int) 1e9 + 9};
vector<int> ps = {517, 1797, 600, 700};

int MOD;
int p;
const int MAXN = 1e6;
int ppow[MAXN];

int add(int a, int b) {
    return (a + b) % MOD;}
int mul(int a, int b) { return int((ll) a * b % MOD);}

struct Hash {
    int val, len;
};

bool operator==(const Hash &a, const Hash &b) {
    return tie(a.val, a.len) == tie(b.val, b.len);
}

Hash merge(Hash a, Hash b) {
    return {add(mul(a.val, ppow[b.len]), b.val), a.len + b.len};
}

int n;
string s;

vector<vector<Hash>> hsh;

void build(int v, int l, int r, int lvl) {
    if (lvl == -1) {
        assert(l + 1 == r);
        hsh[v] = {{s[l], 1}};
        return;
    }
    int m = (l + r) / 2;
    build(2 * v + 1, l, m, lvl - 1);
    build(2 * v + 2, m, r, lvl - 1);
    hsh[v].resize(r - l);
    for (int i = 0; i < (r - l) >> 1; i++) {
        hsh[v][i] = merge(hsh[2 * v + 1][i], hsh[2 * v + 2][i]);
        hsh[v][i + ((r - l) >> 1)] = merge(hsh[2 * v + 2][i], hsh[2 * v + 1][i]);
    }
}

int min2(int a, int b) {
    if (hsh[0][a] == hsh[0][b]) {
        return a;
    }
    int v1 = 0;
    int v2 = 0;
    for (int lvl = n - 1; lvl >= 0; lvl--) {
        int l1 = 2 * v1 + 1;
        int r1 = 2 * v1 + 2;
        int l2 = 2 * v2 + 1;
        int r2 = 2 * v2 + 2;
        if (a & (1 << lvl)) {
            swap(l1, r1);
        }
        if (b & (1 << lvl)) {
            swap(l2, r2);
        }
        if (hsh[l1][a & ((1 << (lvl)) - 1)] == hsh[l2][b & ((1 << (lvl)) - 1)]) {
            v1 = r1;
            v2 = r2;
        } else {
            v1 = l1;
            v2 = l2;
        }
    }
    if (hsh[v1][0].val < hsh[v2][0].val)
        return a;
    return b;
}

void solve() {
    cin >> n;
    cin >> s;
    hsh.resize(1 << (n + 1));
    build(0, 0, 1 << n, n - 1);
    int mn = 0;
    for (int i = 1; i < (1 << n); i++) {
        mn = min2(mn, i);
    }
    string s2(1 << n, '?');
    for (int i = 0; i < (1 << n); i++) {
        s2[i ^ mn] = s[i];}

    cout << s2 << endl;
}

signed main() {
    MOD = MODS[rd() % (int) MODS.size()];
    p = ps[rd() % sz(ps)];
    ppow[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        ppow[i] = mul(ppow[i - 1], p);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}