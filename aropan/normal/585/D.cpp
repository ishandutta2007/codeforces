#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

struct TTask {
    int l, m, w;
};

struct TVar {
    int i;
    pair <int, int> d;
    int v;
};

typedef vector <TVar> TVars;
typedef vector <TTask> TTasks;

TVars generate(TTasks &v) {
    TVars r;
    for (int i = 0; ; ++i) {
        int x = i;
        int l, m, w;
        l = m = w = 0;
        for (size_t j = 0; j < v.size(); ++j) {
            int y = x % 3;
            x /= 3;
            if (y != 2) { l += v[j].l; }
            if (y != 1) { m += v[j].m; }
            if (y != 0) { w += v[j].w; }
        }
        if (x) {
            break;
        }
        r.push_back({i, make_pair(m - l, w - l), l});
    }
    return r;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    cin >> n;
    vector <TTask> v;
    for (int i = 0; i < n; ++i) {
        int l, m, w;
        cin >> l >> m >> w;
        v.push_back({l, m, w});
    }
    TTasks fs(v.begin(), v.begin() + n / 2);
    TTasks  sc(v.begin() + n / 2, v.end());
    TVars a = generate(fs);
    TVars b = generate(sc);
    map < pair <int, int>, TVar> m;
    for (auto& i : a) {
        auto it = m.find(i.d);
        if (it == m.end() || it->second.v < i.v) {
            m[i.d] = i;
        }
    }

    const int INF = (int)1e+9 + 7;
    int result = -INF;
    pair <int, int> answer;
    for (auto& i : b) {
        auto p = make_pair(-i.d.first, -i.d.second);
        auto it = m.find(p);
        if (it == m.end() || it->second.v + i.v <= result) {
            continue;
        }
        result = it->second.v + i.v;
        answer = make_pair(it->second.i, i.i);
    }

    if (result == -INF) {
        cout << "Impossible" << endl;
    } else {
        vector <int> ans;
        int x;
        x = answer.first;
        for (int j = 0; j < n / 2; ++j) {
            ans.push_back(x % 3);
            x /= 3;
        }

        x = answer.second;
        for (int j = 0; j < (int)v.size() - n / 2; ++j) {
            ans.push_back(x % 3);
            x /= 3;
        }
        for (auto& i : ans) {
            if (i != 2) { cout << "L"; }
            if (i != 1) { cout << "M"; }
            if (i != 0) { cout << "W"; }
            cout << "\n";
        }
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}