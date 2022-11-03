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
//#define int ll
#define mp(a) make_pair(a)

#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
//#pragma comment(linker, "/stack:16777216")

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

void solution() {
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> a(n);
    int cur = 0, left = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = left; j < k; ++j) {
            a[j] += s[cur];
            ++cur;
        }
        for (int j = k - 1; j >= 0; --j) {
            if (j == 0 || a[j - 1] != a[k - 1]) {
                left = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = a[i].size(); j < l; ++j) {
            a[i] += s[cur];
            ++cur;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << a[i] << '\n';
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