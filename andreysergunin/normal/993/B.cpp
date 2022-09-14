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
typedef long double ld;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("input.txt", "w", stdout);

    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) {
            swap(a[i].first, a[i].second);
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
        if (b[i].first > b[i].second) {
            swap(b[i].first, b[i].second);
        }
    }

    vector<int> t(10);

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < m; ++v) {
            pair<int, int> p = a[u], q = b[v];

            if (p == q) {
                continue;
            }

            if (p.first == q.first) {
                t[p.first] = 1;
            }

            if (p.first == q.second) {
                t[p.first] = 1;
            }
            
            if (p.second == q.first) {
                t[p.second] = 1;
            }

            if (p.second == q.second) {
                t[p.second] = 1;
            }
        }
    }

    int s = 0;
    int res = 0;
    for (int i = 1; i < 10; ++i) {
        s += t[i];
        if (t[i]) {
            res = i;
        }
    }

    if (s == 1) {
        cout << res << endl;
        return 0;
    }

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < m; ++v) {
            pair<int, int> p = a[u], q = b[v];

            if (p == q) {
                continue;
            }

            if (p.first == q.second) {
                swap(q.first, q.second);
            }
            
            if (p.second == q.first) {
                swap(p.first, p.second);
            }

            if (p.second == q.second) {
                swap(q.first, q.second);
                swap(p.first, p.second);
            }

            if (p.first != q.first) {
                continue;
            }

            int x = p.first;
            int y = p.second;
            int z = q.second;

            bool f = true;


            for (int i = 0; i < n; ++i) {
                if (b[v] == a[i]) {
                    continue;
                }
                if (a[i].first == z || a[i].second == z) {
                    f = false;
                }
            }

            for (int j = 0; j < m; ++j) {
                if (a[u] == b[j]) {
                    continue;
                }
                if (b[j].first == y || b[j].second == y) {
                    f = false;
                }
            }

            if (!f) {
                cout << -1 << endl;
                return 0; 
            }



        }
    }





    cout << 0 << endl;
    return 0;
}