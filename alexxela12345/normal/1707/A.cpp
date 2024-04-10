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

#line 2 "main.cpp"

using namespace Quark;

mt19937 rd(179);

struct node {
    node *l, *r;
    int sz;
    int val;
    int mod;
    int y;
    node(int val) : val(val) {
        l = r = NULL;
        sz = 1;
        mod = 0;
        y = rd();
    }
};

int get_sz(node *a) {
    return (a == NULL) ? 0 : a->sz;
}

void push(node *a) {
    if (!a)
        return;
    if (a->mod == 0)
        return;
    if (a->l) {
        a->l->mod += a->mod;
    }
    if (a->r) {
        a->r->mod += a->mod;
    }
    a->val += a->mod;
    a->mod = 0;
}

void pull(node *a) {
    a->sz = 1 + get_sz(a->l) + get_sz(a->r);
}

node *merge(node *a, node *b) {
    push(a);
    push(b);
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->y > b->y) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    b->l = merge(a, b->l);
    pull(b);
    return b;
}

pair<node *, node *> split_sz(node *n, int k) {
    if (n == NULL)
        return {n, n};
    push(n);
    if (get_sz(n->l) >= k) {
        auto pp = split_sz(n->l, k);
        n->l = pp.second;
        pull(n);
        return {pp.first, n};
    }
    auto pp = split_sz(n->r, k - 1 - get_sz(n->l));
    n->r = pp.first;
    pull(n);
    return {n, pp.second};
}

int get_first(node *n) {
    push(n);
    if (n->l == NULL)
        return n->val;
    return get_first(n->l);
}

vector<int> _tmp;

void _to_vec(node *n) {
    if (n == NULL)
        return;
    push(n);
    _to_vec(n->l);
    _tmp.push_back(n->val);
    _to_vec(n->r);
}

vector<int> to_vec(node *n) {
    _tmp.clear();
    _to_vec(n);
    return _tmp;
}

struct vec {
    int st;

    node *vec;
};

vec init(int q) {
    return {q, new node(0)};
}

void upd(vec &v, int a) {
    int iend = min(get_sz(v.vec), v.st - a + 1);
    auto pp = split_sz(v.vec, iend);
    if (pp.first) {
        pp.first->mod++;
    }
    if (pp.second) {
        int fst = get_first(pp.second);
        pp.second->mod++;
        pp.second = merge(new node(fst), pp.second);
    }
    v.vec = merge(pp.first, pp.second);
    if (get_sz(v.vec) > v.st + 1) {
        v.vec = split_sz(v.vec, v.st + 1).first;
    }
}

int amx(vec &v) {
    auto vec = to_vec(v.vec);
    pair<int, int> mx = {-1, -1};
    for (int i = 0; i < sz(vec); i++) {
        mx = max(mx, {vec[i], v.st - i});
    }
    return mx.second;
}

void Quark::solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vec v = init(q);
        for (int ai : a) {
            upd(v, ai);
#ifdef LOCAL
            auto tmp = to_vec(v.vec);
            for (auto &el : tmp) {
                cout << el << " ";
            }
            cout << endl;
#endif
        }
        int end = amx(v);
#ifdef LOCAL
        cout << end << '\n';
#endif
        string ans;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= end) {
                ans.push_back('1');
            } else if (a[i] > end + 1 && q >= end + 1) {
                end++;
                ans.push_back('1');
            } else {
                ans.push_back('0');
            }
        }
        reverse(all(ans));
        cout << ans << '\n';
#ifdef LOCAL
        cout << "#######" << endl;
#endif
    }
}