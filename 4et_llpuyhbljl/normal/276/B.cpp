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
const long long INF = 1e18;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 100100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int d1, d2, r1, r2, c1, c2;
int a[2][2];
vector<pair<int, int>>ps;
void paic() {
    for (int i = 0; i < 2; ++i) {
        cout << a[i][0] << " " << a[i][1] << "\n";
    }
    exit(0);
}
void solve(int lvl) {
    if (lvl == 4) {
        if (d1 == a[0][0] + a[1][1] && d2 == a[1][0] + a[0][1] && r1 == a[0][0] + a[0][1] && r2 == a[1][0] + a[1][1] && c1 == a[0][0] + a[1][0] && c2 == a[0][1] + a[1][1]) {
            paic();
        }
        return;
    }
    int x, y;
    tie(x, y) = ps[lvl];
    a[x][y] = -1;
    for (int chi = 1; chi <= 9; ++chi) {
        bool check = true;
        for (auto x : ps) {
            check &= a[x.first][x.second] != chi;
        }
        if (check) {
            a[x][y] = chi;
            solve(lvl + 1);
            a[x][y] = -1;
        }
    }
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
   //  file_inc();
    string s;
    cin >> s;
    vector<int>a(26, 0);
    for (auto x : s)++a[x - 'a'];
    int ct = 0;
    for (auto x : a)if (x % 2 == 1)++ct;
    if (ct == 0 || ct % 2 == 1)cout << "First";
    else cout << "Second";
    return 0;
}