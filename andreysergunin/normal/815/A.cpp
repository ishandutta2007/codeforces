#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int INF = 1e9;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    int anss = INF;
    vector<int> ansx, ansy;

    vector<int> x(n), y(m);
    for (int c = 0; c <= g[0][0]; ++c) {
        x[0] = c;
        bool f = true;
        for (int j = 0; j < m; ++j) {
            y[j] = g[0][j] - x[0];
            if (y[j] < 0)
                f = false;
        }
        for (int i = 1; i < n; ++i) {
            x[i] = g[i][0] - y[0];
            if (x[i] < 0)
                f = false;
        }


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (x[i] + y[j] != g[i][j]) {
                    f = false;
                }
            }
        }

        if (!f) {
            continue;
        }

        int s = 0;
        for (int i = 0; i < n; ++i)
            s += x[i];
        for (int j = 0; j < m; ++j)
            s += y[j];

        if (s < anss) {
            anss = s;
            ansx = x;
            ansy = y;
        }
    } 

    if (anss == INF) {
        cout << -1 << "\n";
        return 0;
    }

    int s = anss;
    x = ansx;
    y = ansy;
    
    cout << s << "\n";
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < x[i]; ++k) {
            cout << "row " << i + 1 << "\n";
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int k = 0; k < y[j]; ++k) {
            cout << "col " << j + 1 << "\n";
        }
    }
    return 0;



}