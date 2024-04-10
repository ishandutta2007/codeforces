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

#define sqr(x) ((x) * (x))
#define int ll

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

const ld PI = 3.141592653589793;
const ld EPS = 1e-9;
const int N = (int)1e5;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

void dfs(int v, pii sz, vvi& a, vii& res, int p = -1) {
    int n = (int)a[v].size() - 1;
    for (int u : a[v]) {
        if (u == p)
            continue;
        int m = a[u].size() - 1;
        res[u] = { -(m * n - 1) * sz.first - m * res[v].first, -(m * n - 1) * sz.second - m * res[v].second };
        dfs(u, { res[v].first + n * sz.first, res[v].second + n * sz.second }, a, res, v);
    }
    return;
}

void solution() {
    int n;
    cin >> n;
    vvi a(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vii res(n);
    int start = rand() % n;
    res[start] = { 1, 0 };
    dfs(start, { 0, 1 }, a, res);
    set<int> not_sz;
    int l = -N, r = N;
    for (int i = 0; i < n; ++i) {
        if (res[i].second != 0 && res[i].first % res[i].second == 0)
            not_sz.insert(-res[i].first / res[i].second);
        if (res[i].second > 0) {
            l = max(l, (int)ceil((ld)(-N - res[i].first) / res[i].second));
            r = min(r, (int)floor((ld)(N - res[i].first) / res[i].second));
        }
        if (res[i].second < 0) {
            r = min(l, (int)floor((ld)(-N - res[i].first) / res[i].second));
            l = max(r, (int)ceil((ld)(N - res[i].first) / res[i].second));
        }
    }
    int sz = 0;
    for (int i = 1; i <= r; ++i) {
        if (not_sz.find(i) == not_sz.end()) {
            sz = i;
            break;
        }
    }
    if (sz == 0) {
        for (int i = 0; i >= l; --i) {
            if (not_sz.find(i) == not_sz.end()) {
                sz = i;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << res[i].first + sz * res[i].second << ' ';
    cout << '\n';
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solution();

    return 0;
}