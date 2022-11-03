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
const int N = 1e2 + 5;

int lst[N][N];
int sum[N];

void solution() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> lst[i][j];
            sum[j] += lst[i][j];
        }
    }
    pii ans = { m, 0 };
    for (int i = 0; i < n - 1; i++) {
        int res = 0;
        int cur = sum[n - 1] - sum[i];
        vector < int > dif;
        for (int j = 0; j < m; j++) {
            dif.push_back(lst[j][i] - lst[j][n - 1]);
        }
        sort(all(dif));
       // reverse(all(dif));
        for (int j = 0; j < m; j++) {
           // cout << i << ' ' << dif[j] << endl;
            if (cur <= 0) {
                break;
            }
            cur += dif[j];
            res++;
        }
        ans = min(ans, { res, i });
    }
    cout << ans.first<< endl;
    vector < pii > dif;
    for (int j = 0; j < m; j++) {
        dif.push_back({ lst[j][ans.second] - lst[j][n - 1], j });
    }
    sort(all(dif));
    //reverse(all(dif));
    for (int i = 0; i < ans.first; i++) {
        cout << dif[i].second + 1 << ' ';
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