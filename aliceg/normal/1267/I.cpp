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
const int N = 20;

map<pii, bool> mapp;

bool comp(int i, int j) {
    if (i == j)
        return 0;
    if (mapp.find({ i, j }) != mapp.end())
        return mapp[{i, j}];
    cout << "? " << i << ' ' << j << endl;
    char c;
    cin >> c;
    mapp[{i, j}] = c == '<';
    return c == '<';
}

bool comp1(const pii& a, const pii& b) {
    return comp(a.first, b.first);
}

void solution() {
    mapp.clear();
    int n;
    cin >> n;
    vii p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = { i + 1, n + i + 1 };
        if (comp(p[i].second, p[i].first))
            swap(p[i].second, p[i].first);
    }
    while (p.size() * 2 > n + 2) {
        stable_sort(p.rbegin(), p.rend(), comp1);
        pii x = { p[p.size() - 1].second, p[p.size() - 2].second };
        p.pop_back();
        p.pop_back();
        if (comp(x.second, x.first))
            swap(x.second, x.first);
        p.push_back(x);
    }
    stable_sort(p.rbegin(), p.rend(), comp1);
    if (p.size() * 2 == n + 2) {
        swap(p.back().first, p.back().second);
        stable_sort(p.rbegin(), p.rend(), comp1);
    }
    cout << '!' << endl;
}

signed main() {
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    srand(133708);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solution();
    
    return 0;
}