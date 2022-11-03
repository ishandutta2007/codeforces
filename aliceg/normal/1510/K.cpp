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

const int inf = 1e9 + 7;
const ld pi = 3.141592653589793;
const ld eps = 1e-9;
const int N = 3e3 + 5;
int lst[N];
int cop1[N];
int cop2[N];

pii get_pair(int i) {
    return make_pair(min(lst[i], lst[i + 1]), max(lst[i], lst[i + 1]));
}

bool ok(int n) {
    for (int i = 0; i < n; i++) {
        if (lst[i] != i) return false;
    }
    return true;
}


void update(int& x, int v) {
    if (x == 2) {
        x = v;
    }
    else {
        if (x != v) {
            cout << -1;
            exit(0);
        }
    }
}

void mir(int n) {
    for (int i = 0; i * 2 < n; i++) {
        swap(lst[i], lst[i + n / 2]);
    }
}

void sw(int n) {
    for (int i = 0; i < n; i += 2) {
        swap(lst[i], lst[i + 1]);
    }
}

int gomir(int n) {
    for (int i = 0; i < n; i++) {
        cop1[i] = lst[i];
    }
    if (ok(n)) {
        return 0;
    }
    for (int i = 0; i < n + 10; i++) {
        if (i % 2) {
            sw(n);
        } else {
            mir(n);
        }
        if (ok(n)) {
            for (int i = 0; i < n; i++) {
                lst[i] = cop1[i];
            }
            return i + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        lst[i] = cop1[i];
    }
    return -1;
}


int gosw(int n) {
    if (ok(n)) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cop2[i] = lst[i];
    }
    sw(n);
    int a = gomir(n);
    if (a == -1) {
        return -1;
    }
    return a + 1;
    for (int i = 0; i < n; i++) {
        lst[i] = cop2[i];
    }
}

void solution() {
    int n;
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
        lst[i]--;
    }
    int ans = 0;
    cout << min(gosw(n), gomir(n));
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