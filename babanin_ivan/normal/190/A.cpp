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

int n, m;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    if (m == 0) {
        cout << n << " " << n << endl;
        return 0;
    }
    if (n == 0 && m > 0) {
        printf("Impossible\n");
        return 0;
    }
    if (n >= m) {
        printf("%d ", n);
    }
    else printf("%d ", n + (m - n));
    printf("%d\n", n + (m - 1));
    return 0;
}