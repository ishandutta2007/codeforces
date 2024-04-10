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
const long long INF = 1e9;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 100010, maxT = 2001;

int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n, q;
    cin >> n >> q;
    set<int>vl;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        vl.insert(tmp);
    }
    multiset<int>mm;
    auto it = vl.begin();
    for (int i = 0; i < n - 1; ++i) {
        auto it1 = it;
        ++it;
        int tmp = (*it) - (*it1);
        mm.insert(tmp);
    }
    int v1 = (*vl.begin());
    auto ii = vl.end();
    --ii;
    v1 = (*ii) - v1;
    if (!mm.empty()) {
        auto ii1 = mm.end();
        --ii1;
        v1 -= (*ii1);
    }
    cout << v1 << "\n";
    while (q--) {
        int t, h;
        cin >> t >> h;
        if (t == 0) {
            auto y = vl.lower_bound(h);
            auto y1 = y;
            ++y1;
            if (y1 != vl.end()) {
                mm.erase(mm.find((*y1) - h));
            }
            if (y != vl.begin()) {
                --y;
                mm.erase(mm.find(h - (*y)));
                ++y;
            }
            if (y1 != vl.end() && y != vl.begin()) {
                --y;
                mm.insert((*y1) - (*y));
                ++y;
            }
            vl.erase(y);
        }
        else {
            auto y = vl.lower_bound(h);
            if (y != vl.begin()) {
                --y;
                mm.insert(h - (*y));
                ++y;
            }
            if (y != vl.end()) {
                mm.insert((*y) - h);
            }
            if (y != vl.begin() && y != vl.end()) {
                auto y1 = y;
                --y1;
                mm.erase(mm.find((*y) - (*y1)));
            }
            vl.insert(h);
        }
        if (vl.empty()) {
            cout << 0 << "\n";
            continue;
        }
        int v1 = (*vl.begin());
        auto ii = vl.end();
        --ii;
        v1 = (*ii) - v1;
        if (!mm.empty()) {
            auto ii1 = mm.end();
            --ii1;
            v1 -= (*ii1);
        }
        cout << v1 << "\n";
    }
    return 0;
}
/*
long long x, y, k;
        cin >> x >> y >> k;
        long long tmp = y * k + k - 1;
        cout << (tmp + x - 1) / x + k << "\n";
*/