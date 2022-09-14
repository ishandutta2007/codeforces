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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);
 
const int MAXN = 300;
const int INF = 1e8;
 
int g[MAXN][MAXN];
int d[MAXN][MAXN];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);      
 
    int n;
    cin >> n;
 
    vector<ll> a;
    
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x == 0) {
            continue;
        }
        a.push_back(x);
    }
 
    n = sz(a);
 
    if (n > 120) {
        cout << 3 << endl;
        return 0;
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] & a[j]) {
                g[i][j] = 1;
                g[j][i] = 1;
            } else {
                g[i][j] = INF;
                g[j][i] = INF;
            }
        }
    } 
 
    int res = INF;
    
    for (int w = 0; w < n; ++w) {
        memcpy(d, g, sizeof(g));
 
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == w || j == w || k == w) {
                        continue;
                    }
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
 
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g[w][i] == 1 && g[w][j] == 1) { 
                    res = min(res, d[i][j] + 2);
                }
            }
        }
 
    } 
 
    cout << (res == INF ? -1 : res) << endl;
 
}