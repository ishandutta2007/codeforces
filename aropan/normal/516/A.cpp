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

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    cin >> n;
    int a[10];
    memset(a, 0, sizeof(a));
    while (n) {
        int x = n % 10;
        n /= 10;
        if (x < 2) {
            continue;
        }
        for (int i = 2; i <= x; ++i) {
            int y = i;
            for (int j = 2; j <= y; ++j) {
                while (y % j == 0) {
                    a[j] += 1;
                    y /= j;
                }
            }
        }
    }
    for (int x = 9; x >= 0; --x) {
        bool prime = true;
        for (int j = 2; j < x; ++j) {
            if (x % j == 0) {
                prime = false;
                break;
            }
        }
        if (!prime) {
            continue;
        }
        while (a[x]) {
            cout << x;
            for (int i = 2; i <= x; ++i) {
                int y = i;
                for (int j = 2; j <= y; ++j) {
                    while (y % j == 0) {
                        a[j] -= 1;
                        y /= j;
                    }
                }
            }
        }
    }
    cout << endl;
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}