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
// typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 5e5;
int x[MAXN], y[MAXN];

int len(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int len(int i, int j, int k) {
    return len(i, j) + len(i, k) + len(j, k);
}

int main() {
    
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
    

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    int l = 1e8, d = 1e8, r = -1e8, u = -1e8;

    int lu = -2e8, ld = -2e8, ru = -2e8, rd = -2e8;

    for (int i = 0; i < n; ++i) {
        l = min(x[i], l);
        r = max(x[i], r);
        d = min(y[i], d);
        u = max(y[i], u);
        ru = max(ru, x[i] + y[i]);
        lu = max(lu, x[i] - y[i]);
        rd = max(rd, - x[i] + y[i]);
        ld = max(ld, - x[i] - y[i]);
    }   

    // cout << l << " " << r << " " << u << " " << d << endl;
    // cout << ru << " " << lu << " " << rd << " " << ld << endl;

    vector<int> arr;

    int r3 = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] == l || x[i] == r || y[i] == u || y[i] == d) {
            arr.push_back(i);
            continue;
        }

        if (x[i] + y[i] == ru || x[i] - y[i] == lu || - x[i] + y[i] == rd || - x[i] - y[i] == ld) {
            arr.push_back(i);
        }
    }

    for (int i = 0; i < sz(arr); ++i) {
        for (int j = i; j < sz(arr); ++j) {
            for (int k = i; k < sz(arr); ++k) {
                r3 = max(r3, len(arr[i], arr[j], arr[k]));
            }
        }
    }

    cout << r3 << " ";
    for (int i = 0; i < n - 3; ++i) {
        cout << 2 * (r - l) + 2 * (u - d) << " ";
    }
    cout << endl;
}