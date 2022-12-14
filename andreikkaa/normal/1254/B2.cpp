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


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    vector<ll> pr;
    for(ll i = 2; i * i <= sum; ++i) {
        while(sum % i == 0) {
            sum /= i;
            pr.push_back(i);
        }
    }
    if(sum > 1) {
        pr.push_back(sum);
        sum = 1;
    }

    pr.erase(unique(all(pr)), pr.end());


    ll ans = LLONG_MAX;
    for(ll k : pr) {
        //cout << k << "!" << endl;
        ll cur = 0;
        auto b = a;

        for(int i = 0; i < n; ) {
            //cout << i << endl;

            if(b[i] % k == 0) {
                ++i;
                continue;
            }

            ll res = b[i] % k;
            if(res <= k / 2) {
                cur += res;
                b[i] -= res;
                assert(i + 1 < n);
                b[i + 1] += res;
                ++i;
            } else {
                res = k - res;
                int j;
                for(j = i + 1; res; ++j) {
                    assert(j < n);
                    ll val = min(b[j], res);
                    b[i] += val;
                    b[j] -= val;
                    cur += (j - i) * val;
                    res -= val;
                }
                i = j - 1;
            }
        }

        ans = min(ans, cur);
    }

    if(ans == LLONG_MAX) {
        ans = -1;
    }
    cout << ans << endl;
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