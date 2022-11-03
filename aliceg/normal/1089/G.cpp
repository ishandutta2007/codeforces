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
const int N = 300;

void solution() {
    int n = 0;
    vi a(7);
    int k;
    cin >> k;
    for (int i = 0; i < 7; ++i) {
        cin >> a[i];
        if (a[i])
            ++n;
    }
    int ans = (k + n - 1) / n - 1, x = (k - 1) % n + 1;
    int res = 7;
    for (int i = 0; i < 7; ++i) {
        int s = 0;
        for (int j = 0; j < 7; ++j) {
            s += a[(i + j) % 7];
            if (s == x) {
                res = min(res, j + 1);
                break;
            }
        }
    }
    cout << ans * 7 + res << '\n';
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solution();
    
    return 0;
}