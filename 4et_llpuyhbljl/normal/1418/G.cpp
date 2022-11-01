#pragma comment(linker, "/STACK:2759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
//#define int long long
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 1e10;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 500100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
struct MC {
    long long mx, ct, to_push;
    MC(int MX = 0, int CT = 0, int TO_PUSH = 0) {
        mx = MX;
        ct = CT;
        to_push = TO_PUSH;
    }
    MC(MC a, MC b) {
        mx = max(a.mx, b.mx);
        to_push = ct = 0;
        if (mx == a.mx)ct += a.ct;
        if (mx == b.mx)ct += b.ct;
    }
};
int sz = 1;
MC tree[maxN * 4];
void push(int v) {
    tree[v].mx += tree[v].to_push;
    if (v < sz) {
        tree[2 * v + 1].to_push += tree[v].to_push;
        tree[2 * v].to_push += tree[v].to_push;
    }
    tree[v].to_push = 0;
}
void set_val(int ql, int qr, int v, int tl, int tr, long long val) {
    if (ql <= tl && tr <= qr) {
        tree[v].to_push += val;
        push(v);
        return;
    }
    push(v);
    int m = (tl + tr) / 2;
    if (ql <= m)set_val(ql, qr, 2 * v, tl, m, val);
    else push(2 * v);
    if (qr > m)set_val(ql, qr, 2 * v + 1, m + 1, tr, val);
    else push(2 * v + 1);
    tree[v] = MC(tree[2 * v], tree[2 * v + 1]);
}
int get_ct(int ql, int qr, int v, int tl, int tr) {
    push(v);
    if (ql <= tl && tr <= qr)if (tree[v].mx == 0)return tree[v].ct;
    else return 0;
    int m = (tr + tl) / 2, res = 0;
    if (ql <= m)res += get_ct(ql, qr, 2 * v, tl, m);
    else push(2 * v);
    if (qr > m)res += get_ct(ql, qr, 2 * v + 1, m + 1, tr);
    else push(2 * v + 1);
    tree[v] = MC(tree[2 * v], tree[2 * v + 1]);
    return res;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    //file_inc();
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto& x : a)cin >> x;
    while (sz <= n)sz <<= 1;
    for (int i = 0; i < sz; ++i)tree[sz + i].ct = 1;
    for (int i = sz - 1; i > 0; --i) {
        tree[i].ct = 2 * tree[i * 2].ct;
    }
    vector<vector<int>>rf(n + 1);
    for (auto& x : rf)x.push_back(0);
    for (int i = 0; i < n; ++i) {
        rf[a[i]].push_back(i + 1);
    }
    vector<int>yk(n + 1, 1);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = i + 1, vl = a[i];
        int ct_vls = yk[vl];
        set_val(rf[vl][ct_vls - 1] + 1, rf[vl][ct_vls], 1, 0, sz - 1, -1);
        if (ct_vls >= 3)set_val(rf[vl][ct_vls - 3] + 1, rf[vl][ct_vls - 2], 1, 0, sz - 1, 1);
        if (ct_vls >= 4)set_val(0, rf[vl][ct_vls - 3], 1, 0, sz - 1, -INF);
        ans += get_ct(1, j, 1, 0, sz - 1);
        ++yk[vl];
    }
    cout << ans;
    return 0;
}