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

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#define idbg(x) #x " = " << x
#include "pretty_print.h"
#else
#define dbg(x)
#define idbg(x) ""
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

vector<int> P;

int get(int l, int r) {
    cout << "? ";
    cout << r - l + 1;
    for (int i = l; i <= r; ++i) {
        cout << " " << i;
    }
    cout << endl;

    int ret;

#ifdef LOCAL
    ret = 0;
    for (int i = l; i <= r; ++i) {
        chmax(ret, P[i - 1]);
    }
    dbg(ret);
    return ret;
#endif

    cin >> ret;
    return ret;
}

int main(int /* argc */, char** /* argv */)
{
    srand(time(NULL));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> q;
        for (int i = 0; i < k; ++i) {
            int m;
            cin >> m;
            vector<int> a(m);
            for (int i = 0; i < m; ++i) {
                cin >> a[i];
            }
            q.push_back(a);
        }

#ifdef LOCAL
        P.resize(n);
        for (int i = 0; i < n; ++i) {
            P[i] = rand() % n;
        }
        dbg(P);
#endif
        int m = get(1, n);
        int l = 1;
        int r = n;
        while (l < r) {
            int c = (l + r) / 2;
            if (get(l, c) == m) {
                r = c;
            } else {
                l = c + 1;
            }
        }
        dbg(l);

        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            bool has_max = false;
            set<int> st;
            for (int j = 0; j < (int)q[i].size(); ++j) {
                int x = q[i][j];
                has_max |= x == l;
                st.insert(x);
            }
            if (!has_max) {
                ans.push_back(m);
                continue;
            }
            cout << "? ";
            cout << n - q[i].size();
            for (int i = 1; i <= n; ++i ){
                if (!st.count(i)) {
                    cout << " " << i;
                }
            }
            cout << endl;

            int ret;
            cin >> ret;
            ans.push_back(ret);
        }

        cout << "!";
        for (auto& x : ans) {
            cout << " " << x;
        }

        cout << endl;
        string ret;
        cin >> ret;
        if (ret == "Incorrect") {
            break;
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}