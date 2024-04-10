#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned long ul;

template<class T> void minimize(T & x, const T & y) {
    if (y < x) x = y;
}
template<class T> void maximize(T & x, const T & y) {
    if (x < y) x = y;
}
template<class T> T sqr(T x) { return x * x; }

const ld EPS = acos(-1.0);
const int INF = (int)1e9 + 5;
const ll LINF = (ll)1e18 + 5;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    string dirs;
    cin >> dirs;

    vector<int> d(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    vector<bool> used(n, false);

    int v = 0;

    while (!used[v]) {
        used[v] = true;
        if (dirs[v] == '<') {
            v -= d[v];
        }
        else {
            v += d[v];
        }
        if (v < 0 || v >= n) {
            cout << "FINITE" << endl;
            exit(0);
        }
    }

    cout << "INFINITE" << endl;

    return 0;
}