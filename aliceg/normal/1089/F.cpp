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

pii gcd(int a, int b) {
    if (!b)
        return { 1, 0 };
    pii p = gcd(b, a % b);
    return { p.second, p.first - a / b * p.second };
}

void solution() {
    int n;
    cin >> n;
    int d1 = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                d1 *= i;
            }
            break;
        }
    }
    int d2 = n;
    if (d1 == 1 || d2 == 1) {
        cout << "NO";
        return;
    }
    pii p = gcd(d2, d1);
    int x = -p.first, y = -p.second;
    if (y < 0) {
        swap(x, y);
        swap(d1, d2);
    }
    int k = abs(x) / d1;
    x += d1 * (k + 1);
    y -= d2 * k;
    vii ans;
    for (int i = 0; i < x / (d1 - 1); ++i)
        ans.push_back({ d1 - 1, d1 });
    if (x % (d1 - 1))
        ans.push_back({ x % (d1 - 1), d1 });
    for (int i = 0; i < y / (d2 - 1); ++i)
        ans.push_back({ d2 - 1, d2 });
    if (y % (d2 - 1))
        ans.push_back({ y % (d2 - 1), d2 });
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (pii res : ans)
        cout << res.first << ' ' << res.second << '\n';
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solution();
    
    return 0;
}