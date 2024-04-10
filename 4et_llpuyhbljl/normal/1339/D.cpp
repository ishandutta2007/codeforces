#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<ctime>
#include<bitset>
#include<random>
using namespace std;
//#define double long long;
typedef unsigned long long ull;
#define double long double
const double e = 0.00000005;
const double pi = 3.1415926535898;
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
//const long long INF = 100000000000000;
const int Y = 100100;
const int INF = 100000000;
const long long m = 998244353;
bool dg[Y];
int ll[Y];
int way[2 * Y];
int L = -1;
int ID[Y];
vector<int>Ed[Y];
int dpt[Y];
pair<int, int> tree[8 * Y];
int sz = 1;
void dfs(int i, int p, int d = 1) {
    way[++L] = i;
    ID[i] = L;
    dpt[i] = d;
    for (auto x : Ed[i]) {
        if (x == p)continue;
        dfs(x, i, d + 1);
        way[++L] = i;
    }
}
void build() {
    for (int i = 0; i <= L; ++i)tree[i + sz] = { dpt[way[i]],way[i] };
    for (int i = sz - 1; i > 0; --i)tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}
pair<int, int> get(int ql, int qr, int v, int tl, int tr) {
    if (ql <= tl && tr <= qr)return tree[v];
    pair<int, int>res = { INF,INF };
    int mid = (tr + tl) / 2;
    if (ql <= mid)res = min(res, get(ql, qr, 2 * v, tl, mid));
    if (qr > mid)res = min(res, get(ql, qr, 2 * v + 1, mid + 1, tr));
    return res;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    for (int i = 0; i < 8 * Y; ++i)tree[i] = { INF,INF };
    int n;
    cin >> n;
    int MN = 1;
    int MX = n - 1;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        Ed[a].push_back(b);
        Ed[b].push_back(a);
        ++ll[a];
        ++ll[b];
    }
    int fl = -1;
    for(int i = 1; i <= n; ++i) {
        if (ll[i] == 1) {
            if (fl == -1) {
                fl = i;
            }
            for (auto x : Ed[i])dg[x] = true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dg[i]) {
            ++MX;
            for (auto x : Ed[i]) {
                if (ll[x] == 1)--MX;
            }
        }
    }
    dfs(1, -1);
    while (sz <= (L + 1))sz <<= 1;
    build();
    for(int i = fl +1;i<=n;++i) {
        int a = fl, b = i;
        if (ll[b] != 1)continue;
        int dd = dpt[a] + dpt[b];
        a = ID[a];
        b = ID[b];
        pair<int, int>res = get(min(a, b), max(a, b), 1, 0, sz - 1);
        int lo = dd - 2 * dpt[res.second];
        if (lo % 2 == 1) {
            MN = 3;
            break;
        }
    }
    MX = max(MX, MN);
    cout << MN << " " << MX;
    return 0;
}
/*
782574093100800
1
782574093100800 1
*/