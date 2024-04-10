#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, a[300300];
int dp[33][300300];

int calc(int bon, int ind) {
    if (ind == n) return 0;
    int &res = dp[bon][ind];
    if (res != -1) return res;
    res = a[ind] + calc(min(bon + a[ind]/10, 31), ind + 1);
    for (int i = 1; i <= bon && i <= a[ind]; i++) {
        res = min(res, a[ind] - i + calc(bon - i, ind + 1));
    }
    return res;
}

int main(){

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        a[i] /= 100;
    }

    memset(dp, -1, sizeof dp);

    printf("%d\n", calc(0, 0) * 100);

    return 0;
}