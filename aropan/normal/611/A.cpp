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
    char s[30];
    while (scanf("%d of %s", &n, s) == 2) {
        int answer = -1;
        if (strcmp(s, "month") == 0) {
            const int a[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            answer = 0;
            for (int i = 0; i < 12; ++i) {
                answer += n <= a[i];
            }
        } else {
            int m = 366 - 3;
            answer = m / 7;
            if (n <= m % 7) answer += 1;
            if (5 <= n) answer += 1;
        }
        cout << answer << endl;
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}