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

int t, x, y, p, q;

void solve() {
    scanf("%d%d%d%d", &x, &y, &p, &q);
    ll a, b;
    ll k = 0;
    if (p == 0) {
        if (x == 0) printf("0\n");
        else printf("-1\n");
        return;
    }
    if (p == q) {
        if (x < y) printf("-1\n");
        else printf("0\n");
        return;
    }
    k = max(k, (x + p - 1) / p * 1ll);
    k = max(k, (y + q - 1) / q * 1ll);
    k = max(k, (y - x + q - p - 1) / (q - p) * 1ll);
    a = k * p - x;
    b = k * q - y;
    printf("%lld\n", b);
}

int main(){

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}