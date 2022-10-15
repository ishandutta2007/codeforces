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

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    cout << 1;
    if (k == 1) {
        for (int i = 2; i <= n; ++i) {
            cout << " " << i;
        }
        cout << endl;
        return 0;
    }
    for (int i = n; i > k + 1; --i) {
        cout << " " << i;
    }
    k += 1;
    for (int i = 2; i <= k; ++i) {
        cout << " " << k;
        if (i <= --k)
            cout << " " << i;
    }
    cout << endl;

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}