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

int n;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    int cmax = 0;
    bool f = false;
    for (int z = 0; z < 2 * n + 1; ++z) {
        string t;
        t.clear();
        for (int i = 0; i < cmax; ++i) {
            t.pb(char(int('0') + i));
            t.pb(' ');
        }
        for (int i = 0; i < 2 * (n - cmax); ++i)
            printf(" ");
        printf("%s", t.c_str());
        printf("%d", cmax);
        reverse(t.begin(), t.end());
        printf("%s", t.c_str());
        printf("\n");
        if (cmax == n)
            f = !f;
        if (!f)
            ++cmax;
        else --cmax;
    }
    return 0;
}