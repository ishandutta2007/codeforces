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
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n);
    vector<int> used(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    vector<int> p(2 * n, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        p[u] = v;
        p[v] = u;
    }

    int t;
    cin >> t;

    for (int i = 0; i < 2 * n; ++i) {
        t = 3 - t;
        if (t == 2) {
            bool finish = false;

            for (int j = 0; j < 2 * n; ++j) {
                if (!used[j] && p[j] != -1) {
                    if (used[p[j]]) {
                        used[j] = true;
                        cout << j + 1 << endl;
                        finish = true;
                        break;
                    }
                }
            }

            if (finish) {
                continue;
            }

            for (int j = 0; j < 2 * n; ++j) {
                if (!used[j] && p[j] != -1) {
                    if (a[j] < a[p[j]]) {
                        used[p[j]] = true;
                        cout << p[j] + 1 << endl;
                    } else {
                        used[j] = true;
                        cout << j + 1 << endl;
                    }
                    finish = true;
                    break;
                }
            }

            if (finish) {
                continue;
            }

            int k = -1;
            for (int j = 0; j < 2 * n; ++j) {
                if (used[j]) {
                    continue;
                }
                if (k == -1 || a[k] < a[j]) {
                    k = j;
                }
            }

            used[k] = true; 
            cout << k + 1 << endl;
        } else {
            int k;
            cin >> k;
            --k;
            used[k] = true;
        }

    }


}