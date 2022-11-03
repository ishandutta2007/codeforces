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
const int N = 2e6 + 1;
int cnt[N];
int used[N];

bool ok(int x, int i) {
    return (x % i == 0 || (x - 1) / i + 1 >= (i - x % i));
}

void build(int x, int a) {
    for (int i = 1; i <= x + 1; i++) {
        if (ok(x, i)) {
            used[i] += a;
        }
    }
}

int upd(int x, int n) {
    int res = 1;
    for (int i = 1; i <= x + 1; i++) {
        if (used[i] == n) {
            res = i;
        }
    }
    return res;
}

void solution() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x - 1]++;
    }
    vector < int > cur;
    for (int i = 0; i < n; i++) {
        if (cnt[i]) {
            cur.push_back(cnt[i]);
        }
    }
    for (auto v : cur) {
        build(v, 1);
    }
    int res = upd(cur[0], sz(cur));
    int sum = 0;
    for (auto v : cur) {
        sum += (v - 1) / res + 1;
    }
    cout << sum << endl;
    for (auto v : cur) {
        build(v, -1);
    }
    fill(cnt, cnt + n, 0);
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