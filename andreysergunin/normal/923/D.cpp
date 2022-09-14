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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;  

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout); 


    string s, t;
    cin >> s >> t;
    int n = sz(s);
    int m = sz(t);

    vector<vector<int>> a(n + 1, vector<int>(3));
    vector<vector<int>> b(m + 1, vector<int>(3));

    vector<int> pa(n + 1);
    vector<int> pb(m + 1);

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            pa[i + 1] = pa[i] + 1;
        } else {
            pa[i + 1] = 0;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (t[i] == 'A') {
            pb[i + 1] = pb[i] + 1;
        } else {
            pb[i + 1] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[i + 1][j] = a[i][j] + (s[i] == (char)('A' + j));
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j) {
            b[i + 1][j] = b[i][j] + (t[i] == (char)('A' + j));
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int lf1, lf2, rg1, rg2;
        cin >> lf1 >> rg1;
        cin >> lf2 >> rg2;
        --lf1;
        --lf2;

        vector<int> x(3);
        vector<int> y(3);
        for (int j = 0; j < 3; ++j) {
            x[j] = a[rg1][j] - a[lf1][j];
            y[j] = b[rg2][j] - b[lf2][j];
        }

        // cout << x[0] << " " << x[1] << " " << x[2] << endl;
        // cout << y[0] << " " << y[1] << " " << y[2] << endl;

        x[1] += x[2];
        y[1] += y[2];


        if (y[1] < x[1] || (y[1] - x[1]) % 2 != 0) {
            cout << 0;
            continue;
        }

        int u = min(pa[rg1], rg1 - lf1);
        int v = min(pb[rg2], rg2 - lf2);

        if (u < v) {
            cout << 0;
            continue;
        }

        if (x[1] == y[1]) {
            if ((u - v) % 3 == 0) {
                cout << 1;
            } else {
                cout << 0;
            }
            continue;
        }

        if (x[1] == 0) {
            if (u == v) {
                cout << 0;
            } else {
                cout << 1;
            }
        } else {
            cout << 1;
        }
    }

    cout << endl;


    return 0;
}