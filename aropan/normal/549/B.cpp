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

#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__)
#define INT64 "%I64d"
#define UNS64 "%I64u"
#else
#define INT64 "%lld"
#define UNS64 "%llu"
#endif

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
    #endif
    int n;
    while (cin >> n) {
        vector <string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < n; ++j) {
                a[i][j] -= '0';
            }
        }
        vector <int> k(n);
        queue <int> q;
        for (int i = 0; i < n; ++i) {
            cin >> k[i];
            if (k[i] == 0) {
                q.push(i);
            }
        }
        vector <int> ans;
        while (q.size()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (int i = 0; i < n; ++i) {
                if (a[x][i]) {
                    if (--k[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        cout << ans.size() << "\n";
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) {
                cout << " ";
            }
            cout << ans[i] + 1;
        }
        cout << "\n";
    }
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}