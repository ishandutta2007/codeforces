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

typedef pair < pair <ll, ll>, int> triple;

#define X first.first
#define Y first.second
#define I second

triple z;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n) {
        vector <triple> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].X >> v[i].Y;
            v[i].I = i + 1;
        }
        sort(v.begin(), v.end());

        for (int i = 2; i < n; ++i) {
            if ((v[i].X - v[0].X) * (v[1].Y - v[0].Y) - (v[i].Y - v[0].Y) * (v[1].X - v[0].X) != 0) {
                swap(v[2], v[i]);
                break;
            }
        }
        cout << v[0].I << " " << v[1].I << " " << v[2].I << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}