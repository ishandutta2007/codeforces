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


void _solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    vector<int> c;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        c.push_back(a[i].x);
        c.push_back(a[i].y);
    }

    sort(all(c));
    c.erase(unique(all(c)), c.end());

    int mx = 0;
    for(auto &i : a) {
        i.x = lower_bound(all(c), i.x) - c.begin();
        i.y = lower_bound(all(c), i.y) - c.begin();
        i.x *= 2;
        i.y *= 2;
        mx = max(mx, i.y);
    }

    mx += 2;
    vector<vector<int>> op(mx), cl(mx);
    for(int i = 0; i < n; ++i) {
        op[a[i].x].push_back(i);
        cl[a[i].y].push_back(i);
    }

    vector<pair<int, int>> cnt(mx);

    set<int> now;
    for(int i = 0; i < mx; ++i) {
        for(int j : op[i]) {
            now.insert(j);
        }

        if(sz(now) == 0) {
            // ok
        } else if(sz(now) == 1) {
            cnt[i] = {1, *now.begin()};
        } else {
            cnt[i] = {2, -1};
        }

        for(int j : cl[i]) {
            now.erase(j);
        }
    }

    int def = 0;
    for(int i = 1; i < mx; ++i) {
        if(cnt[i].x == 0 && cnt[i - 1].x != 0) {
            ++def;
        }
    }

    if(def == n) {
        cout << n - 1 << endl;
        return;
    }

    vector<int> ans(n);

    for(int i = 0; i < mx; ) {
        if(cnt[i].x == 1) {
            int r = i + 1;
            while(cnt[r].x == 1) {
                ++r;
            }
            if(i != 0 && cnt[i - 1].x == 2 && cnt[r].x == 2) {
                ++ans[cnt[i].y];
            }

            i = r;
        } else {
            ++i;
        }
    }

    cout << *max_element(all(ans)) + def << endl;
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

    int t;
    cin >> t;
    while(t--) {
        _solve();
    }

#ifdef LOCAL
    cerr << "TIME: " << (ld)clock() / CLOCKS_PER_SEC << "\n";
#endif

    return 0;
}