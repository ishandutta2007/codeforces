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
const int N = 1e3 + 5;

void dfs(int v, vvi& a, vi& d, int p = -1) {
    if (p == -1)
        d[v] = 0;
    else
        d[v] = d[p] + 1;
    for (int u : a[v]) {
        if (u == p)
            continue;
        dfs(u, a, d, v);
    }
    return;
}

vi get_path(vi& p, int v) {
    vi res;
    while (p[v] != -1) {
        res.push_back(p[v]);
        v = p[v];
    }
    return res;
}

bool dfs1(int v, vvi& a, vi& d, vi& ans, int& cnt, vi& pr, int& min_d, int k, int p = -1) {
    min_d = min(min_d, d[v]);
    ++cnt;
    ans.push_back(v);
    if (min_d + cnt == k) {
        vi path = get_path(pr, v);
        ans.insert(ans.end(), path.begin(), path.end());
        return true;
    }
    for (int u : a[v]) {
        if (u == p || u == pr[v])
            continue;
        if (dfs1(u, a, d, ans, cnt, pr, min_d, k, v))
            return true;
        ans.push_back(v);
    }
    if (pr[v] != -1 && pr[v] != p) {
        if (dfs1(pr[v], a, d, ans, cnt, pr, min_d, k, v))
            return true;
        ans.push_back(v);
    }

    return false;
}

void solution() {
    int n, k;
    cin >> n >> k;
    vvi a(n);
    vi p(n, -1);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
        a[p[i]].push_back(i);
        a[i].push_back(p[i]);
    }
    vi d(n);
    dfs(0, a, d);
    int v = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] >= d[v])
            v = i;
        if (d[i] + 1 == k) {
            vi ans = get_path(p, i);
            reverse(all(ans));
            cout << k - 1 << '\n';
            for (int i = 0; i < ans.size(); ++i)
                cout << ans[i] + 1 << ' ';
            cout << i + 1 << '\n';
            return;
        }
    }
    int min_d = d[v], cnt = 0;
    vi ans;
    dfs1(v, a, d, ans, cnt, p, min_d, k);
    reverse(ans.begin(), ans.end());
    cout << (int)ans.size() - 1 << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
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