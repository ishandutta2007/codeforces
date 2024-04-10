#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

vector<string> rot(vector<string> a) {
    int n = sz(a);
    vector<string> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = "";
        for (int j = 0; j < n; ++j) {
            b[i] += "1";
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[j][n - 1 - i] = a[i][j];
        }
    }
    return b;
}

vector<string> flip_ver(vector<string> a) {
    int n = sz(a);
    vector<string> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = "";
        for (int j = 0; j < n; ++j) {
            b[i] += "1";
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][n - 1 - j] = a[i][j];
        }
    }
    return b;
}

vector<string> flip_hor(vector<string> a) {
    int n = sz(a);
    vector<string> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = "";
        for (int j = 0; j < n; ++j) {
            b[i] += "1";
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[n - i - 1][j] = a[i][j];
        }
    }
    return b;
}

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<string> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int mask = 0; mask < 4; ++mask) {
        for (int r = 0; r < 4; ++r) {
            vector<string> curr = a;
            if (bit(mask, 0)) {
                curr = flip_hor(curr);
            }
            if (bit(mask, 1)) {
                curr = flip_ver(curr);
            }
            for (int i = 0; i < r; ++i) {
                curr = rot(curr);
            }
            if (curr == b) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";

}