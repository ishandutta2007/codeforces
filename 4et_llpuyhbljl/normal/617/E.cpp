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
const long long INF = 3e18;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 2000100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int p[maxN];
const int sz = 320;
long long ans[maxN];
long long tmp = 0;
long long ct[maxN];
bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    int a1, a2, a3, b1, b2, b3;
    tie(a1, a2, a3) = a;
    tie(b1, b2, b3) = b;
    return make_tuple(a1 / sz, a2, a3) < make_tuple(b1 / sz, b2, b3);
}
int k;
void add(int id) {
    int nw = p[id];
    int bf = k ^ nw;
    if (nw == bf) {
        tmp -= ct[nw] * (ct[nw] - 1) / 2;
    }
    else {
        tmp -= ct[nw] * ct[bf];
    }
    ++ct[nw];
    if (nw == bf) {
        tmp += ct[nw] * (ct[nw] - 1) / 2;
    }
    else {
        tmp += ct[nw] * ct[bf];
    }
}
void del(int id) {
    int nw = p[id];
    int bf = k ^ nw;
    if (nw == bf) {
        tmp -= ct[nw] * (ct[nw] - 1) / 2;
    }
    else {
        tmp -= ct[nw] * ct[bf];
    }
    --ct[nw];
    if (nw == bf) {
        tmp += ct[nw] * (ct[nw] - 1) / 2;
    }
    else {
        tmp += ct[nw] * ct[bf];
    }
}
void solve1(int n, int q) {
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i] ^= p[i - 1];
    }
    vector<tuple<int, int, int>>t(q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        t[i] = make_tuple(a - 1, b + 1, i);
    }
    sort(t.begin(), t.end(), cmp);
    int l = -500, r = -500;
    for (auto x : t) {
        int l1, r1, id;
        tie(l1, r1, id) = x;
        if (l1 / sz != l / sz) {
            tmp = 0;
            l = l1;
            r = l1;
            fill(begin(ct), end(ct), 0);
        }
        while (r < r1) {
            add(r++);
        }
        if (l < l1) {
            while (l < l1)del(l++);
        }
        else {
            while (l > l1)add(--l);
        }
        ans[id] = tmp;
    }
    for (int i = 0; i < q; ++i)cout << ans[i] << "\n";
}
void solve0(int n, int q) {
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i] ^= p[i - 1];
    }
    vector<tuple<int, int, int>>t(q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        t[i] = make_tuple(a, b, i);
    }
    sort(t.begin(), t.end(), cmp);
    int l = -500, r = -500;
    for (auto x : t) {
        int l1, r1, id;
        tie(l1, r1, id) = x;
        if (l1 / sz != l / sz) {
            tmp = 0;
            l = l1;
            r = l1;
            fill(begin(ct), end(ct), 0);
        }
        while (r < r1) {
            add(r++);
        }
        if (l < l1) {
            while (l < l1)del(l++);
        }
        else {
            while (l > l1)add(--l);
        }
        ans[id] = tmp + (ct[p[l - 1]] + ct[p[r]]);
        if (p[l - 1] == p[r])++ans[id];
    }
    for (int i = 0; i < q; ++i)cout << ans[i] << "\n";
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    // file_inc();
    int n, q;
    cin >> n >> q >> k;
    if (k != 0)solve1(n, q);
    else solve0(n, q);
    return 0;
}