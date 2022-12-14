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
        ""
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

int ask_cross(int a, int b, int c) {
    cout << "2 " << a << " " << b << " " << c << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

ll ask_sq(int a, int b, int c) {
    cout << "1 " << a << " " << b << " " << c << endl;
    cout.flush();
    ll ans;
    cin >> ans;
    return ans;
}


void solve() {
    int n;
    cin >> n;

    vector<int> pos;
    vector<int> neg;

    for(int i = 3; i <= n; ++i) {
        auto res = ask_cross(1, 2, i);
        if(res == 1) {
            pos.push_back(i);
        } else {
            assert(res == -1);
            neg.push_back(i);
        }
    }

    vector<ll> sq(n + 1);
    for(int i = 3; i <= n; ++i) {
        sq[i] = ask_sq(1, 2, i);
    }

    vector<int> ans = {1};

    auto cmp_ls = [&](int i, int j) {
        return sq[i] < sq[j];
    };

    auto cmp_gr = [&](int i, int j) {
        return sq[i] > sq[j];
    };

    if(!pos.empty()) {
        int p3 = pos[0];
        for (int i : pos) {
            if (sq[i] > sq[p3]) {
                p3 = i;
            }
        }

        vector<int> b13, b23;
        for(int i : pos) {
            if(i != p3) {
                auto res = ask_cross(1, p3, i);
                if (res > 0) {
                    b13.push_back(i);
                } else {
                    b23.push_back(i);
                }
            }
        }

        sort(all(b13), cmp_ls);
        ans.insert(ans.end(), all(b13));

        ans.push_back(p3);
        sort(all(b23), cmp_gr);
        ans.insert(ans.end(), all(b23));
    }

    ans.push_back(2);

    if(!neg.empty()) {
        int p4 = neg[0];
        for (int i : neg) {
            if (sq[i] > sq[p4]) {
                p4 = i;
            }
        }

        vector<int> b24, b14;
        for(int i : neg) {
            if(i != p4) {
                auto res = ask_cross(2, p4, i);
                if(res > 0) {
                    b24.push_back(i);
                } else {
                    b14.push_back(i);
                }
            }
        }

        sort(all(b24), cmp_ls);
        ans.insert(ans.end(), all(b24));

        ans.push_back(p4);

        sort(all(b14), cmp_gr);
        ans.insert(ans.end(), all(b14));
    }

    assert(sz(ans) == n);

    if(ask_cross(ans[0], ans[1], ans[2]) < 0) {
        reverse(all(ans));
        rotate(ans.begin(), ans.end() - 1, ans.end());
    }
    assert(ans[0] == 1);

    cout << "0";
    for(int i : ans) {
        cout << " " << i;
    }
    cout << endl;
    cout.flush();
}

void _solve() {
    solve();
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
    cerr << "PIDOR TIME: " << (ld)clock() / CLOCKS_PER_SEC << "\n";
#endif

    return 0;
}