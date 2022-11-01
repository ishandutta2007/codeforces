#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int a[2000];

int gcd(int x, int y) {
    if (x % y == 0)
        return y;
    return gcd(y, x % y);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int ans = 0;
    int tmp = a[0];
    for (int i = 1; i < n; ++i)
        tmp = gcd(tmp, a[i]);
    for (int i = 0; i < n; ++i)
        a[i] /= tmp;
    ans = a[0] - 1;
    for (int i = 1; i < n; ++i)
        ans += a[i] - a[i - 1] - 1;

        if (ans & 1)
            cout << "Alice\n";
        else cout << "Bob\n";
    return 0;
}