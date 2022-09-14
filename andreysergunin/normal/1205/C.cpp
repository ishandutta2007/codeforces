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

const int MAXN = 60;

bool ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    int x;
    cin >> x;
    return x;
}

int n;
int a[2][MAXN][MAXN];

void print(int k) {
    cout << "!" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[k][i][j];
        }
        cout << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);      
    
    cin >> n;

    memset(a, -1, sizeof(a));
    a[0][0][0] = 1;
    a[0][0][1] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (i >= 1 && j >= 1) {
                a[0][i][j] = a[0][i - 1][j - 1] ^ (1 - ask(i - 1, j - 1, i, j));
            } else if (j >= 2) {
                a[0][i][j] = a[0][i][j - 2] ^ (1 - ask(i, j - 2, i, j));
            }
        }
        if (i >= 1) {
            a[0][i][0] = a[0][i][2] ^ (1 - ask(i, 0, i, 2));
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2 == 1) {
                a[1][i][j] = a[0][i][j] ^ 1;
            } else {
                a[1][i][j] = a[0][i][j];
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << a[0][i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // return 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + 3 < n) {
                vector<int> f(2, false);
                for (int k = 0; k < 2; ++k) {
                    f[k] |= (a[k][i][j] == a[k][i + 3][j] && a[k][i + 1][j] == a[k][i + 2][j]);
                }
                if (f[0] != f[1]) {
                    int x = ask(i, j, i + 3, j);
                    int k = (x == f[0] ? 0 : 1);
                    print(k);
                    return 0;
                }
            }


            if (j + 3 < n) {
                vector<int> f(2, false);
                for (int k = 0; k < 2; ++k) {
                    f[k] |= (a[k][i][j] == a[k][i][j + 3] && a[k][i][j + 1] == a[k][i][j + 2]);
                }
                if (f[0] != f[1]) {
                    int x = ask(i, j, i, j + 3);
                    int k = (x == f[0] ? 0 : 1);
                    print(k);
                    return 0;
                }
            }

            if (i + 2 < n && j + 1 < n) {
                vector<int> f(2, false);

                for (int k = 0; k < 2; ++k) {
                    f[k] |= (a[k][i][j] == a[k][i + 2][j + 1] && a[k][i + 1][j] == a[k][i + 2][j]);
                    f[k] |= (a[k][i][j] == a[k][i + 2][j + 1] && a[k][i + 1][j] == a[k][i + 1][j + 1]);
                    f[k] |= (a[k][i][j] == a[k][i + 2][j + 1] && a[k][i][j + 1] == a[k][i + 1][j + 1]);
                }


                if (f[0] != f[1]) {
                    int x = ask(i, j, i + 2, j + 1);
                    int k = (x == f[0] ? 0 : 1);
                    print(k);
                    return 0;
                }
            }

            if (i + 1 < n && j + 2 < n) {
                vector<int> f(2, false);

                for (int k = 0; k < 2; ++k) {
                    f[k] |= (a[k][i][j] == a[k][i + 1][j + 2] && a[k][i][j + 1] == a[k][i][j + 2]);
                    f[k] |= (a[k][i][j] == a[k][i + 1][j + 2] && a[k][i][j + 1] == a[k][i + 1][j + 1]);
                    f[k] |= (a[k][i][j] == a[k][i + 1][j + 2] && a[k][i + 1][j] == a[k][i + 1][j + 1]);
                }

                if (f[0] != f[1]) {
                    int x = ask(i, j, i + 1, j + 2);
                    int k = (x == f[0] ? 0 : 1);
                    print(k);
                    return 0;
                }
            }

        }   
    }
    assert(false);
}