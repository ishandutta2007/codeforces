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

int n, a[222][10];
int type[10];
int ans = inf;
int cnt[6];
int dp[122][122][7];

int get_score(int t) {
    return (t + 1) * 500;
}

int calc(int id) {
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        if (a[id][i] != -1) {
            int score = get_score(type[i]);
            int delta = score / 250;
            ans += score - delta * a[id][i];
        }
    }
    return ans;
}

int get_type(int a, int b) {
    if (a * 2 > b) return 0;
    if (a * 4 > b) return 1;
    if (a * 8 > b) return 2;
    if (a * 16 > b) return 3;
    if (a * 32 > b) return 4;
    return 5;
}

bool unsolved_can(int a, int b, int t, int y) {
    if (t == 5) {
        return 32 * a <= b + y;
    }
    int p = (1 << t);
    int q = (p << 1);
    return (a * p <= b + y && b + y < a * q);
}

bool solved_can(int a, int b, int t, int y) {
    if (t == 5) {
        return 32 * a <= b + y;
    }
    int p = (1 << t);
    int q = (p << 1);
    int lx = 0, rx = y;
    int tmp = b + y - q * a;
    if (tmp >= 0) lx = max(lx, tmp / q + 1);
    if (b + y - p * a >= 0) rx = min(rx, (b + y - p * a) / p);
    else return false;
    return lx <= rx;
}

void solve() {
    if (calc(0) <= calc(1)) return;
    int res = inf;
    for (int y = 0; y <= 32 * n; y++) {
        bool ok = 1;
        for (int i = 0; i < 5 && ok; i++) {
            if (a[0][i] == -1) {
                ok &= unsolved_can(cnt[i], n, type[i], y);
            } else {
                ok &= solved_can(cnt[i], n, type[i], y);
            }
        }
        if (ok) {
            ans = min(ans, y);
            return;
        }
    }
}

void rec(int ind) {
    if (ind == 5) {
        solve();
        return;
    }
    for (int i = 0; i < 6; i++) {
        type[ind] = i;
        rec(ind + 1);
    }
}

int main(){

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != -1) cnt[j]++;
        }
    }

    rec(0);

    if (ans == inf) ans = -1;

    printf("%d\n", ans);

    return 0;
}