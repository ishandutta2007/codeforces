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
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1000003;
set <int> l[MAXN], r[MAXN];
int n, m;
int x;
set <int> v;
vector <int> ans;

bool rec(set <int> &v)
{
    int curr = x;
    //cout << curr << ":";
    //for (auto &i : v) {
        //cout << " " << i;
    //}
    //cout << endl;
    for (auto &i : l[curr]) {
        if (i <= x) {
            return false;
        }
        v.erase(i);
    }
    if (l[curr].size()) {
        x += 1;
        if (!rec(l[curr])) {
            return false;
        }
    }

    ans.push_back(curr);

    while (v.size() && *v.begin() <= x) {
        v.erase(v.begin());
    }

    for (auto &i : r[curr]) {
        if (i <= x) {
            return false;
        }
        v.insert(i);
    }

    if (v.size()) {
        x += 1;
        if (!rec(v)) {
            return false;
        }
    }
    return true;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    #endif

    srand(time(NULL));
    while (cin >> n >> m) {
    //for (int iter = 0; iter < 1000000; ++iter) {
        //cout << endl;
        //n = rand() % 50 + 50;
        //m = rand() % 5 + 3;
        //cout << n << " " << m << "\n";
        for (int i = 1; i <= n; ++i) {
            l[i].clear();
            r[i].clear();
        }
        bool ok = true;
        for (int i = 0; i < m; ++i) {
            int a, b;
            string c;
            cin >> a >> b >> c;
            //do {
                //a = rand() % n + 1;
                //b = rand() % n + 1;
            //} while (a == b);
            //c = (rand() % 2? "LEFT" : "RIGHT");
            //cout << a << " " << b << " " << c << endl;

            ok &= a < b;

            if (c == "LEFT") {
                l[a].insert(b);
            } else {
                r[a].insert(b);
            }
        }
        v.clear();
        for (int i = 1; i <= n; ++i) {
            v.insert(i);
        }

        x = 1;
        ans.clear();
        if (!ok || !rec(v)) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (size_t i = 0; i < ans.size(); ++i) {
                if (i) {
                    cout << " ";
                }
                cout << ans[i];
            }
            cout << "\n";
        }
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}