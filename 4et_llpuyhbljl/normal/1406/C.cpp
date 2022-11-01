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
const long long INF = 1e18;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 300000, maxT = 2001;
vector<vector<int>>G;
vector<int>dp, mx, cl;
void dfs(int v, int p) {
    for (auto x : G[v]) {
        if (x == p)continue;
        dfs(x, v);
        dp[v] += dp[x];
        if (dp[x] > mx[v]) {
            mx[v] = dp[x];
            cl[v] = 1;
        }
        else {
            if (dp[x] == mx[v]) ++cl[v];
        }
    }
    int tmp = (int)G.size() - dp[v];
    if (tmp > mx[v]) {
        mx[v] = tmp;
        cl[v] = 1;
    }
    else {
        if (tmp == mx[v]) ++cl[v];
    }
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        G.assign(n, {});
        dp.assign(n, 1);
        mx.assign(n, 0);
        cl.assign(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(0, -1);
        int nm = mx[0];
        int c = 0;
        for (auto x : mx) {
            if (x < nm) {
                nm = x;
                c = 1;
            }
            else if (x == nm)++c;
        }
        if (c == 1) {
            cout << 1 << " " << G[0][0] + 1 << "\n";
            cout << 1 << " " << G[0][0] + 1 << "\n";
            continue;
        }
        vector<int>vv;
        for (int i = 0; i < n; ++i)if (mx[i] == nm)vv.push_back(i);
        if ((int)vv.size() > 2) {
            int h = 0;
            while (true) {
                ++h;
            }
        }
        int kh = vv[0];
        int id = -1;
        for (auto x : G[kh]) {
            if (dp[x] != mx[kh] && dp[x] < dp[kh])id = x;
        }
        if (id == -1) {
            for (auto x : G[kh])if (dp[x] > dp[kh])id = x;
        }
        cout << vv[0] + 1 << " " << id + 1 << "\n";
        cout << vv[1] + 1 << " " << id + 1 << "\n";
    }
    return 0;
}
/*
7 12
6 7 1
7 6 1
1 2 2
2 3 1
3 2 1
2 4 2
5 3 2
4 5 1
5 4 1
6 3 5
4 7 3
5 6 2
*/