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

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    cin >> n;
    ll v[n], d[n], p[n];
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> d[i] >> p[i];
    }

    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        if (p[i] < 0) {
            continue;
        }
        ans.push_back(i);
        ll x = v[i];
        ll s = 0;
        for (int j = i + 1; j < n; ++j) {
            if (p[j] < 0) {
                continue;
            }

            p[j] -= x + s;

            x = max(0LL, x - 1);
            if (p[j] < 0) {
                s += d[j];
            }
        }
    }
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) {
            cout << " ";
        }
        cout << ans[i] + 1;
    }
    cout << endl;
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}