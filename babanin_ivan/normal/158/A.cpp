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

int n, k; 
int a[1000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    --k;
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] && (a[i] >= a[k]))
            ++ans;
    cout << ans << endl;
    return 0;
}