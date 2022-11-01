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

int n, m, x, y;
int a[200000];
int b[200000];
vector <pair<int , int> > res;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    scanf("%d %d", &x, &y);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    int i1 = 0;
    int i2 = 0;
    while ((i1 < n) && (i2 < m)) {
        if (b[i2] < a[i1] - x) 
            ++i2;
        else 
            if (b[i2] > a[i1] + y)
                ++i1;
            else {
                ++i1;
                ++i2;
                res.pb(mp(i1, i2));
            }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
        printf("%d %d\n", res[i].fir, res[i].sec);
    return 0;
}