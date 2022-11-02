#pragma comment(linker, "/STACK:64000000")
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
#include <unordered_set>
#include <unordered_map>

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

int n;
int a[5050];
int pr[5050];

int sum(int l, int r) {
    if (l > r) return 0;
    int ans = pr[r];
    if (l) ans -= pr[l - 1];
    return ans;
}

inline int gethash(int hod, int k, int l, int r) {
	return (((l<<20) + (r << 7)+ k)<<1)| hod;
}

int dp[2010][145][71];

inline int calc(int hod, int k, int l, int r) {
    if (l > r) return 0;
    if (k > (r - l + 1)) return 0;
    if(dp[l][(n-r-1-l) + 70][k]!=-1) return dp[l][(n-r-1-l) + 70][k];
    int res;
    if (hod == 0) {
        res = -inf;
        if (l + k - 1 <= r) res = max(res, sum(l, l + k - 1) - calc(1, k, l + k, r));
        if (l + k <= r) res = max(res, sum(l, l + k) - calc(1, k + 1, l + k + 1, r));
    } else {
        res = -inf;
        if (r - k + 1 >= l) res = max(res, sum(r - k + 1, r) - calc(0, k, l, r - k));
        if (r - k >= l) res = max(res, sum(r - k, r) - calc(0, k + 1, l, r - k - 1));
    }
    dp[l][(n-r-1-l) + 70][k] = res;
    return res;
}

int main(){
	
	scanf("%d", &n);
	memset(dp, -1, sizeof dp);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    pr[0] = a[0];
    for (int i = 1; i < n; i++) pr[i] = a[i] + pr[i - 1];

    cout << calc(0, 1, 0, n - 1) << endl;

    return 0;
}