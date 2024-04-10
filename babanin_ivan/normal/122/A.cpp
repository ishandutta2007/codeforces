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

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int x;
    scanf("%d", &x);
    for (int i = 4; i <= x; ++i) {
        if ((x % i) != 0)
            continue;
        bool f = true;
        int j = i;
        while (j) {
            int y = j % 10;
            if ((y != 4) && (y != 7))
                f = false;
            j /= 10;
        }
        if (f) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}