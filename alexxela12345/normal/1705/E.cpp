#line 1 "main.cpp"
#define PRAGMAS
#line 2 "/Users/alex/Templates/template/template.hpp"
#ifdef PRAGMAS
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <codecvt>
#include <complex>
#include <condition_variable>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <thread>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

#include <cassert>
#include <ccomplex>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cwchar>
#include <cwctype>

#line 2 "/Users/alex/Templates/template/macro.hpp"

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int((v).size()))
#line 6 "/Users/alex/Templates/template/util.hpp"

template<typename T>
void unq(std::vector<T> &arr) {
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
}
void unq(std::string &arr) {
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
}
#line 79 "/Users/alex/Templates/template/template.hpp"

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;

namespace Quark {
    void solve();
};

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Quark::solve();
}

#line 3 "main.cpp"

using namespace Quark;

const int MAXN = 2e5 + 228;

int tree[MAXN * 4];
int mod[MAXN * 4];

void push(int v, int l, int r) {
    if (mod[v] == 1) {
        tree[v] = 0;
        if (l + 1 != r)
            mod[2 * v + 1] = mod[2 * v + 2] = 1;
    } else if (mod[v] == 2) {
        tree[v] = r - l;
        if (l + 1 != r)
            mod[2 * v + 1] = mod[2 * v + 2] = 2;
    }
    mod[v] = 0;
}

int get(int v, int l, int r, int ql, int qr) {
    push(v, l, r);
    if (l >= qr || ql >= r) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return tree[v];
    }
    int m = (l + r) / 2;
    return get(2 * v + 1, l, m, ql, qr) + get(2 * v + 2, m, r, ql, qr);
}

int get(int l, int r) {
    return get(0, 0, MAXN, l, r);
}

#define set set228

void set(int v, int l, int r, int ql, int qr, int val) {
    push(v, l, r);
    if (l >= qr || ql >= r)
        return;
    if (ql <= l && r <= qr) {
        mod[v] = val + 1;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    set(2 * v + 1, l, m, ql, qr, val);
    set(2 * v + 2, m, r, ql, qr, val);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

void set(int l, int r, int val) {
    set(0, 0, MAXN, l, r, val);
}

int down1(int v, int l, int r, int ql, int qr) {
    push(v, l, r);
    if (l >= qr || ql >= r)
        return INT_MAX;
    if (ql <= l && r <= qr) {
        if (tree[v] == r - l)
            return INT_MAX;
        if (l + 1 == r)
            return l;
    }
    int m = (l + r) / 2;
    int ans1 = down1(2 * v + 1, l, m, ql, qr);
    if (ans1 == INT_MAX)
        ans1 = down1(2 * v + 2, m, r, ql, qr);
    return ans1;
}

int down2(int v, int l, int r, int ql, int qr) {
    push(v, l, r);
    if (l >= qr || ql >= r)
        return INT_MAX;
    if (ql <= l && r <= qr) {
        if (tree[v] == 0)
            return INT_MAX;
        if (l + 1 == r)
            return l;
    }
    int m = (l + r) / 2;
    int ans1 = down2(2 * v + 1, l, m, ql, qr);
    if (ans1 == INT_MAX)
        ans1 = down2(2 * v + 2, m, r, ql, qr);
    return ans1;
}

void add(int x) {
    // int l = x - 1;
    // int r = MAXN;
    // while (r - l > 1) {
    //     int m = (l + r) / 2;
    //     if (get(x, m) == m - x) {
    //         l = m;
    //     } else {
    //         r = m;
    //     }
    // }
    int l = down1(0, 0, MAXN, x, MAXN);
    set(x, l, 0);
    set(l, l + 1, 1);
}

void rem(int x) {
    // int l = x - 1;
    // int r = MAXN;
    // while (r - l > 1) {
    //     int m = (l + r) / 2;
    //     if (get(x, m) == 0) {
    //         l = m;
    //     } else {
    //         r = m;
    //     }
    // }
    int l = down2(0, 0, MAXN, x, MAXN);
    set(x, l, 1);
    set(l, l + 1, 0);
}

void Quark::solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int el : arr)
        add(el);
    while (q--) {
        int k, l0;
        cin >> k >> l0;
        k--;
        rem(arr[k]);
        arr[k] = l0;
        add(arr[k]);
        int l = 0;
        int r = MAXN;
        while (r - l > 1) {
            int m = (l + r) / 2;
            int val = get(m, MAXN);
            if (val) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << l << '\n';
    }
}