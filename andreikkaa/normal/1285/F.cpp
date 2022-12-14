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

const int A = 100'228;
bool u[A];
vector<pair<int, int>> mults[A];
vector<int> dvs[A];
vector<int> pos[A];
int access[A];


void _solve() {
    for(int i = 2; i < A; ++i) {
        if(dvs[i].empty()) {
            dvs[i] = {i};
            for(int j = i + i; j < A; j += i) {
                dvs[j].push_back(i);
            }
        }
    }

    for(int i = 2; i < A; ++i) {
        const int ss = sz(dvs[i]);
        for(int j = 1; j < (1 << ss); ++j) {
            int cc = 0;
            int p = 1;

            for(int k = 0; k < ss; ++k) {
                if(j >> k & 1) {
                    ++cc;
                    p *= dvs[i][k];
                }
            }

            if(cc % 2 == 0) {
                mults[i].emplace_back(p, 1);
            } else {
                mults[i].emplace_back(p, -1);
            }
        }
    }

    int n = 100'000;
    cin >> n;

    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        int x = i + 1;

        cin >> x;
        ans = max(ans, ll(x));
        u[x] = true;
    }

    for(int g = 1; g < A; ++g) {
        vector<int> nums;
        for(int i = g; i < A; i += g) {
            if(u[i]) {
                nums.push_back(i / g);
            }
        }

        if(sz(nums) <= 1) {
            continue;
        }

        for(int i = 0; i < sz(nums); ++i) {
            for(const auto &j : mults[nums[i]]) {
                if(access[j.x] != g) {
                    access[j.x] = g;
                    pos[j.x].clear();
                }
                pos[j.x].push_back(i);
            }
        }

        auto cntcop = [&nums](int l, int r) {
            int sum = r - l;
            for(const auto &i : mults[nums[r]]) {
                sum += i.y * (lower_bound(all(pos[i.x]), r) - lower_bound(all(pos[i.x]), l));
            }
            assert(sum >= 0);
            return sum > 0;
        };

        int l = 0;
        for(int r = sz(nums) - 1; r > 0 && l < r; --r) {
            while(l < r && cntcop(l, r)) {
                ++l;
            }
            if(l > 0 && cntcop(l - 1, r)) {
                ans = max(ans, ll(nums[l - 1]) * nums[r] * g);
            }
        }

        //cout << g << " " << ans << endl;
    }

    cout << ans << endl;
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