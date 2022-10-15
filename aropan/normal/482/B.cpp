#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstring>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef pair < int, pair < int, int > > mpair;

#define L first
#define R second.first
#define Q second.second

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n, m;
    cin >> n >> m;
    vector < mpair > a;
    for (int i = 0; i < m; ++i) {
        int l, r, q;
        cin >> l >> r >> q;
        l -= 1;
        r -= 1;
        a.push_back(make_pair(l, make_pair(r, q)));
        a.push_back(make_pair(r + 1, make_pair(l, -(q + 1))));
    }
    sort(a.begin(), a.end());

    int ans[n];
    int sum[n];
    memset(ans, 0, sizeof(ans));
    bool ok = true;
    for (int b = 0; b < 31 && ok; ++b) {
        int count = 0;
        for (int i = 0, j = 0; i <= n && ok; ++i) {
            while (j < (int)a.size() && a[j].first == i) {
                if (a[j].Q >= 0) {
                    count += (a[j].Q >> b) & 1;
                } else {
                    int bit = ((-a[j].Q - 1) >> b) & 1;
                    count -= bit;
                    ok &= (sum[i - 1] - (a[j].R? sum[a[j].R - 1] : 0) > 0) ^ bit;
                }
                ++j;
            }
            if (i < n) {
                if (count) {
                    ans[i] |= 1 << b;
                }
                sum[i] = count == 0? 1 : 0;
                if (i) {
                    sum[i] += sum[i - 1];
                }
            }
        }
    }
    if (!ok) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            if (i) {
                cout << " ";
            }
            cout << ans[i];
        }
        cout << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}