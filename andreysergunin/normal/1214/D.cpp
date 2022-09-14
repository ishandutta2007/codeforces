#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif
 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
 
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = (s[j] == '.' ? 0 : 1);
        }
    }
 
    vector<vector<int>> u(n, vector<int>(m));
    vector<vector<int>> v(n, vector<int>(m));
 
    u[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (u[i][j] == 0) {
                continue;
            }
            if (i + 1 < n && !a[i + 1][j]) {
                u[i + 1][j] = 1;
            }
            if (j + 1 < m && !a[i][j + 1]) {
                u[i][j + 1] = 1;
            }
        }
    }
 
    v[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (v[i][j] == 0) {
                continue;
            }
            if (i - 1 >= 0 && !a[i - 1][j]) {
                v[i - 1][j] = 1;
            }
            if (j - 1 >= 0 && !a[i][j - 1]) {
                v[i][j - 1] = 1;
            }
        }
    }
 
    if (v[0][0] == 0) {
        cout << 0 << endl;
        return 0;
    } 

    vector<vector<int>> arr(n + m - 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i + j].push_back(i);
        }
    }

 
    for (int d = 1; d < n + m - 2; ++d) {
        int cnt = 0;
        for (int i : arr[d]) {
            int j = d - i;
 
            if (i < n && j < m) {
                cnt += (v[i][j] && u[i][j]);
            }
        }  
 
        if (cnt == 1) {
            cout << 1 << endl;
            return 0;
        }
 
    }
 
    cout << 2 << endl;
 
 
 
 
#ifdef LOCAL
    cerr << "Time: " << ld(clock()) / CLOCKS_PER_SEC << endl;
#endif
}