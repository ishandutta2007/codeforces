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
const double INF = 1e17;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 100100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
vector<int>gg;
int find(int v) {
    return gg[v] == v ? v : gg[v] = find(gg[v]);
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
  //   file_inc();
    int m, n;
    cin >> m >> n;
    long long s = 0;
    vector<long long>a(m), b(n);
    for (auto& x : a)cin >> x;
    for (auto& x : b)cin >> x;
    gg.assign(n + m, 0);
    for (int i = 0; i < n + m; ++i)gg[i] = i;
    vector<tuple<long long, int, int>>tp;
    for (int i = 0; i < m; ++i) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; ++j) {
            int vertex;
            cin >> vertex;
            --vertex;
            s += a[i] + b[vertex];
            tp.push_back(make_tuple(a[i] + b[vertex], i, m + vertex));
        }
    }
    sort(tp.begin(), tp.end());
    reverse(tp.begin(), tp.end());
    for (auto x : tp) {
        long long cs;
        int i, j;
        tie(cs, i, j) = x;
        if (find(i) == find(j))continue;
        s -= cs;
        gg[find(i)] = find(j);
    }
    cout << s;
    return 0;
}