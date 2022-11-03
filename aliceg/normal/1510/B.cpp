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

bool dfs(int v, vvi& a, vi& back, vc& used) {
    used[v] = 1;
    for (int u : a[v]) {
        if (back[u] == -1) {
            back[u] = v;
            return true;
        }
    }
    for (int u : a[v]) {
        if (used[back[u]])
            continue;
        if (dfs(back[u], a, back, used)) {
            back[u] = v;
            return true;
        }
    }
    return false;
}

void solution() {
    int d, n;
    cin >> d >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vii cnt(n);
    for (int i = 0; i < n; ++i) {
        cnt[i].second = i;
        for (int k = 0; k < d; ++k)
            if (s[i][k] == '1')
                ++cnt[i].first;
    }
    vvi a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            bool t = true;
            for (int k = 0; k < d; ++k) {
                if (s[i][k] == '1' && s[j][k] == '0') {
                    t = false;
                    break;
                }
            }
            if (t)
                a[i].push_back(j);
        }
    }
    sort(cnt.rbegin(), cnt.rend());
    vi back(n, -1);
    vc used(n);
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < n; ++i) {
            int v = cnt[i].second, c = cnt[i].first;
            if (used[v])
                continue;
            vc used1(n);
            if (dfs(v, a, back, used1)) {
                used[v] = 1;
                changed = true;
            }
        }
    }
    vi edges(n, -1);
    for (int i = 0; i < n; ++i) {
        if (back[i] != -1)
            edges[back[i]] = i;
    }
    vi res;
    for (int i = 0; i < n; ++i) {
        if (back[i] != -1)
            continue;
        vc col(d);
        int cur = i;
        while (cur != -1) {
            for (int k = 0; k < d; ++k) {
                if (!col[k] && s[cur][k] == '1') {
                    col[k] = 1;
                    res.push_back(k);
                }
            }
            cur = edges[cur];
        }
        res.push_back(-1);
    }
    res.pop_back();
    cout << res.size() << '\n';
    for (int x : res) {
        if (x == -1)
            cout << "R ";
        else
            cout << x << ' ';
    }
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