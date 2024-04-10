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

const int inf = 1000000007;
const ld eps = 1e-07;

int ans[2][5];

int n;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    int t = 0;
    ans[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        ans[!t][0] = (((ans[t][1] + ans[t][2]) % inf) + ans[t][3]) % inf;
        ans[!t][1] = (((ans[t][0] + ans[t][2]) % inf) + ans[t][3]) % inf;
        ans[!t][2] = (((ans[t][1] + ans[t][0]) % inf) + ans[t][3]) % inf;
        ans[!t][3] = (((ans[t][1] + ans[t][2]) % inf) + ans[t][0]) % inf;
        t = !t;
    }
    cout << ans[t][0] << endl;
    return 0;
}