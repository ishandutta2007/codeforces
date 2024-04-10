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
set <int> a;
int res;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    int x;
    scanf("%d", &x);
    a.insert(x);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &x);
        if (x < *a.begin())
            ++res;
        if (x > *a.rbegin())
            ++res;
        a.insert(x);
    }
    cout << res << endl;
    return 0;
}