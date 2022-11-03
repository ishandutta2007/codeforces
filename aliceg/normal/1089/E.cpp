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
#include <cassert>

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
#ifndef LOCAL
#define endl '\n'
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const int INF = 1e9 + 10;
const ld PI = 3.141592653589793;
const ld EPS = 1e-9;
const int N = 2e5 + 5;

vector < pii > way;

void build() {
    for (int i = 0; i < 8; i++) {
        way.push_back({ i, 0 });
    }
    pii cur = { 7, 1 };
    int d = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            way.push_back(cur);
            cur.second += d;
        }
        cur.second -= d;
        d *= -1;
        cur.first -= 1;
    }
    for (int i = 0; i < 8; i++) {
        way.push_back({ i, 7 });
    }
}

void solution() {
    int n;
    cin >> n;
    build();
    vector < pii > ans;
    if (n == 15) {
        ans.clear();
        for (int i = 0; i < 7; i++) {
            ans.push_back({ i, 0 });
        }
        for (int i = 1; i < 7; i++) {
            ans.push_back({ 6, i });
        }
        ans.push_back({ 5, 6 });
        ans.push_back({ 5, 7 });
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            ans.push_back(way[i]);
        }
        pii p = ans.back();
        if (p.first == 7) {
            ans.push_back({ p.first, p.second + 1 });
        }
        else if (p.second == 7) {
            ans.push_back({ p.first + 1, p.second });
        }
        else {
            ans.push_back({ p.first, 7 });
        }
    }
    ans.push_back({ 7, 7 });
    for (int i = 0; i < sz(ans); i++) {
        cout << char(ans[i].first + 'a') << ans[i].second + 1 << ' ';
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