#pragma comment(linker, "/STACK:9759095000")
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
const long long INF = 1e9;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
vector<string>qq;
map<long long, int > mp;
void bug() {
    int t = 0;
    while (true) {
        cout << ++t;
    }
}
long long pll(long long a, long long b) {
    if (mp[a + b] == 1)return a + b;
    qq.push_back(to_string(a) + " + " + to_string(b));
    if (mp[a] == 0 || mp[b] == 0) {
        bug();
    }
    mp[a + b] = 1;
    return a + b;
}
long long css(long long a, long long b) {
    if (mp[a ^ b] == 1)return a ^ b;
    qq.push_back(to_string(a) + " ^ " + to_string(b));
    if (mp[a] == 0 || mp[b] == 0) {
        bug();
    }
    mp[a ^ b] = 1;
    return a ^ b;
}
long long solve1(long long x) {
    int j;
    long long sb = 1;
    for (int i = 0; i < 50; ++i) {
        //cout << (x & (sb << i)) << endl;
        if ((x & (sb << i)) != 0)j = i;
    }
    int j1;
    for (int i = 0; i < j; ++i) {
        //cout << (x & (sb << i)) << endl;
        if ((x & (sb << i)) != 0)j1 = i;
    }
    int sz = j - j1 - 1;
    long long tmp = x;
    for (int i = 0; i < sz; ++i) {
        tmp = pll(tmp, tmp);
        x = css(x, tmp);
    }
    return x;
}
long long solve2(long long x) {
    int j;
    long long sb = 1;
    for (int i = 0; i < 50; ++i) {
        //cout << (x & (sb << i)) << endl;
        if ((x & (sb << i)) != 0)j = i;
    }
    int j1 = j;
    while (j1 >= 0 && (x & (sb << j1)) != 0)--j1;
    int sz = j - j1;
    long long tmp = x;
    for (int i = 0; i < sz - 1; ++i) {
        tmp = pll(tmp, tmp);
    }
    long long cs = css(tmp, x);
    long long sm = pll(tmp, x);
    long long ss = pll(sm, cs);
    tmp = pll(tmp, tmp);
    ss = css(ss, tmp);
    x = css(x, ss);
    return x;
}
long long solve3(long long x) {
    int sz = 2;
    long long tmp = x;
    for (int i = 0; i < sz - 1; ++i) {
        tmp = pll(tmp, tmp);
    }
    long long cs = css(tmp, x);
    long long sm = pll(tmp, x);
    long long ss = pll(sm, cs);
    tmp = pll(tmp, tmp);
    ss = css(ss, tmp);
    int j;
    long long sb = 1;
    for (int i = 0; i < 50; ++i) {
        //cout << (x & (sb << i)) << endl;
        if ((x & (sb << i)) != 0)j = i;
    }
    int j1 = j;
    while (j1 >= 0 && (x & (sb << j1)) != 0)--j1;
    sz = j - j1 - 1;
    for (int i = 0; i < sz ; ++i) {
        x = css(x, ss);
        ss = pll(ss, ss);
    }
    return x;
}
void show(long long x) {
    long long sb = 1;
    for (int i = 25; i >= 0; --i) {
        //cout << (x & (sb << i)) << endl;
        if ((x & (sb << i)) != 0)cout << 1;
        else cout << 0;
    }
    cout << " " << x << endl;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    // file_inc();
    long long x;
    cin >> x;
    mp[x] = 1;
    while (x != 1) {
        // show(x);
        int j;
        long long sb = 1;
        for (int i = 0; i < 50; ++i) {
            //cout << (x & (sb << i)) << endl;
            if ((x & (sb << i)) != 0)j = i;
        }
        int j1 = j;
        while (j1 >= 0 && (x & (sb << j1)) != 0)--j1;
        if (j1 + 1 == j)x = solve1(x);
        else if (j1 + 2 == j)x = solve2(x);
        else x = solve3(x);
    }
    pll(1, 1);
    if (qq.size() > 100000) {
        bug();
    }
    cout << qq.size() << "\n";
    for (auto x : qq)cout << x << "\n";
    return 0;
}