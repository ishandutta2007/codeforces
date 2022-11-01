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

const int inf=2000000000;
const ld eps=1e-07;

int k;
int a[20];


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >>k;
    for (int i = 0; i < 12; ++i)
        scanf("%d", &a[i]);
    sort(a, a + 12);
    int sum = 0;
    int i = 11;
    int ans = 0;
    while ((sum < k) && (i >= 0)) {
        sum += a[i];
        --i;
        ++ans;
    }
    if (sum < k)
        ans = -1;
    cout << ans << endl;
    return 0;
}