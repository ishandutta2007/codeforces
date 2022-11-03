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
//#pragma comment(linker, "/stack:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const int INF = 1e18 + 10;
const ld PI = 3.141592653589793;
const ld EPS = 1e-9;
const int N = 2e6 + 1;

void solution() {
    int n;
    cin >> n;
    vi a(n), b(n), t(n);
    set<pii> ev;
    multiset<int> fut;
    multiset<int> cur;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> t[i];
        ev.insert({ a[i], -i - 1 });
        ev.insert({ b[i] - t[i], i + 1 });
        fut.insert(a[i] + t[i]);
    }
    ev.insert({ 0, 0 });
    int ans = 0;
    while (!ev.empty()) {
        int x = ev.begin()->first, v = ev.begin()->second;
        ev.erase(ev.begin());
        if (v > 0) {
            --v;
            cur.erase(cur.find(t[v]));
            continue;
        }
        if (v < 0) {
            v = -v - 1;
            fut.erase(fut.find(a[v] + t[v]));
            cur.insert(t[v]);
            continue;
        }
        int cur_t = INF, next_t = INF;
        if (!cur.empty())
            cur_t = *cur.begin();
        if (!fut.empty())
            next_t = *fut.begin();
        if (cur_t == INF && next_t == INF)
            break;
        if (cur_t + x > next_t) {
            ans += 1;
            ev.insert({ next_t, 0 });
            continue;
        }
        int ev_next;
        if (ev.begin()->second > 0)
            ev_next = ev.begin()->first + 1;
        else
            ev_next = ev.begin()->first;
        int k = (min(ev_next, next_t - cur_t + 1) - x + cur_t - 1) / cur_t;
        ans += k;
        ev.insert({ x + k * cur_t, 0 });
    }
    cout << ans;
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