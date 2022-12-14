#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,tune=native")

#define first x
#define second y

#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
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
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;

#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()

#ifndef LOCAL
#define endl '\n'
#endif

const char inpf[] =
#ifdef LOCAL
        "input.txt"
#else
        ""
#endif
;

const char outf[] =
#ifdef LOCAL
        ""
#else
        ""
#endif
;

// =============================================================

const int N = 2228;
int c[N];
vector<int> g[N];
int ans[N];
int ss[N];

int dfs_s(int v) {
    ss[v] = 1;
    for(int i : g[v]) {
        ss[v] += dfs_s(i);
    }
    return ss[v];
}

void dfs(int v, vector<int> a) {
    if(c[v] >= sz(a)) {
        cout << "NO" << endl;
        exit(0);
    }

    ans[v] = a[c[v]];
    a.erase(a.begin() + c[v]);

    int pos = 0;
    for(int i : g[v]) {
        dfs(i, vector<int>(a.begin() + pos, a.begin() + pos + ss[i]));
        pos += ss[i];
    }
}

void _solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        int p;
        cin >> p >> c[i];

        g[p].push_back(i);
    }

    dfs_s(g[0][0]);

    vector<int> vec(n);
    iota(all(vec), 1);
    dfs(g[0][0], vec);

    cout << "YES" << endl;
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}


// =============================================================

int main() {
    if (*inpf != 0) {
        assert(freopen(inpf, "r", stdin));
    }
    if (*outf != 0) {
        assert(freopen(outf, "w", stdout));
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << setprecision(20);
    cout << fixed;

    _solve();

#ifdef LOCAL
    cerr << "TIME: " << (ld)clock() / CLOCKS_PER_SEC << "\n";
#endif

    return 0;
}