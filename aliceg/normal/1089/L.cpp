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

void solution() {
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vvi cnt(k + 1);
    for (int i = 0; i < n; ++i)
        cnt[a[i]].push_back(b[i]);
    int c = 0;
    vi s;
    for (int i = 1; i <= k; ++i) {
        if (cnt[i].empty())
            ++c;
        else {
            sort(all(cnt[i]));
            s.insert(s.end(), cnt[i].begin(), cnt[i].end() - 1);
        }
    }
    sort(s.begin(), s.end());
    int sum = 0;
    for (int i = 0; i < c; ++i)
        sum += s[i];
    cout << sum;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    srand(133708);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solution();
    
    return 0;
}