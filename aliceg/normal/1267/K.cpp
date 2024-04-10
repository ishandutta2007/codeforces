#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <bitset>

#define sqr(x) ((x) * (x))
#define F first
#define S second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define int ll
#define mp(a) make_pair(a)

#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const int INF = 1e9 + 7;
const ld PI = 3.141592653589793;
const ld EPS = 1e-9;
const int N = 20;

int f[N];

int calc_c(int n, int k) {
    return f[n] / f[n - k] / f[k];
}

void solution() {
    int k;
    cin >> k;
    vi p;
    for (int i = 2; k > 0; ++i) {
        p.push_back(k % i);
        k /= i;
    }
    int n = p.size();
    vi a(n + 1);
    for (int i = 0; i < n; ++i)
        a[p[i]]++;
    int res = 1;
    int sum = 0;
    for (int i = n; i > 0; --i) {
        res *= calc_c(n - i + 1 - sum, a[i]);
        sum += a[i];
    }
    if (a[0]) {
        int res1 = 1;
        sum = 0;
        for (int i = n; i > 0; --i) {
            if (n - i + 1 - sum == a[i]) {
                res1 = 0;
                break;
            }
            res1 *= calc_c(n - i - sum, a[i]);
            sum += a[i];
        }
        res -= res1;
    }
    cout << res - 1 << '\n';
    return;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i;

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solution();
    
    return 0;
}