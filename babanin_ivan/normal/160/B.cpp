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

vector <int> a, b;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    scanf("%d ", &n);
    n *= 2;
    for (int i = 0; i < n / 2; ++i) {
        char c;
        scanf(" %c ", &c);
        a.pb(int(c) - int('0'));
    }
    for (int i = 0; i < n / 2; ++i) {
        char c;
        scanf(" %c ", &c);
        b.pb(int(c) - int('0'));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool f = true;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] >= b[i])
            f = false;
    if (f) {
        printf("YES\n");
        return 0;
    }
    f = true;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] <= b[i])
            f = false;
    if (f) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}