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

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> u(h);
    vector<string> v(h - 1);

    for (int i = 0; i < h; ++i) {
        cin >> u[i];
        if (i != h - 1) {
            cin >> v[i];
        }
    }

    if (k == 1) {
        int cnt = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w - 1; ++j) {
                cnt += (u[i][j] == 'E');
            }
            if (i != h - 1) {
                for (int j = 0; j < w; ++j) {
                    cnt += (v[i][j] == 'E');
                }
            }
        }

        if (cnt * 4 >= (w * (h - 1) + (w - 1) * h) * 3) {
            cout << "YES" << endl;
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    cout << "1 ";
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    vector<vector<int>> a(h, vector<int>(w));

    if (w >= h) {
        for (int i = 0; i < h; ++i) {
            a[i][0] = 0;
            for (int j = 0; j < w - 1; ++j) {
                a[i][j + 1] = a[i][j] ^ (u[i][j] == 'N');
            }
        }

        for (int i = 0; i < h - 1; ++i) {
            int cnt = 0;
            for (int j = 0; j < w; ++j) {
                cnt += (a[i][j] ^ (v[i][j] == 'N')) == a[i + 1][j];
            }
            if (2 * cnt < w) {
                for (int j = 0; j < w; ++j) {
                    a[i + 1][j] ^= 1;
                }
            }
        }

        cout << "YES" << endl;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << a[i][j] + 1 << " ";
            }
            cout << endl;
        }
    } else {
        for (int j = 0; j < w; ++j) {
            a[0][j] = 0;
            for (int i = 0; i < h - 1; ++i) {
                a[i + 1][j] = a[i][j] ^ (v[i][j] == 'N');
            }
        }

        for (int j = 0; j < w - 1; ++j) {
            int cnt = 0;
            for (int i = 0; i < h; ++i) {
                cnt += (a[i][j] ^ (u[i][j] == 'N')) == a[i][j + 1];
            }
            if (2 * cnt < h) {
                for (int i = 0; i < h; ++i) {
                    a[i][j + 1] ^= 1;
                }
            }
        }

        cout << "YES" << endl;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << a[i][j] + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}