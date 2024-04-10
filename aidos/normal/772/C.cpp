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

int n, m, used[200200];
int cnt[200200];
vector<int> v;
vector<int> g[200200];
int dp[200200];

int calc(int ind) {
    int &res = dp[ind];
    if (res != -1) return res;
    res = cnt[v[ind]];
    for (int i = ind + 1; i < v.size(); i++) {
        if (v[i] % v[ind] == 0) res = max(res, cnt[v[ind]] + calc(i));
    }
    return res;
}

void rec(int ind, vector<int> &ans) {
    int res = calc(ind);
    forit (it, g[v[ind]]) ans.pb(*it);
    for (int i = ind + 1; i < v.size(); i++) {
        if (v[i] % v[ind] == 0 && res == cnt[v[ind]] + calc(i)) {
            rec(i, ans);
            return;
        }
    }
}

int lp[200200];
vector<int> pr;

int phi(int val) {
    int ans = val;
    while (val > 1) {
        int p = lp[val];
        ans /= p;
        ans *= (p - 1);
        while (val % p == 0) val /= p;
    }
    return ans;
}

int binpow(int a, int k, int m) {
    a %= m;
    if (k == 0) return 1;
    int ans = binpow(a, k / 2, m);
    ans = 1ll * ans * ans % m;
    if (k % 2) ans = 1ll * ans * a % m;
    return ans;
}

int get(int a, int b) {
    if (b == 0) return 0;
    int g = __gcd(a, m);
    int mm = m / g;
    a /= g;
    b /= g;
    int f = phi(mm);
    f--;
    return b * 1ll * binpow(a, f, mm) % mm;
}

int main(){

    for (int i = 2; i < 200200; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0; j < sz(pr) && pr[j] <= lp[i] && i * 1ll * pr[j] < 200200; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        used[x] = 1;
    }

    for (int i = 1; i <= m; i++) {
        if (m % i == 0) v.pb(i);
    }

    for (int i = 0; i < m; i++) {
        if (!used[i]) cnt[__gcd(i, m)]++;
        if (!used[i]) g[__gcd(i, m)].pb(i);
    }

    memset(dp, -1, sizeof dp);

    vector<int> ans;

    rec(0, ans);

    int cur = 1;

    printf("%d\n", calc(0));
    for (int i = 0; i < sz(ans); i++) {
        int target = ans[i];
        // cur * x == target
        int x = get(cur, target);
        if (i > 0) printf(" ");
        printf("%d", x);
        cur = 1ll * cur * x % m;
    }
    printf("\n");

    return 0;
}