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
// default_random_engine generator;
// mt19937 rnd(1);

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> used(3 * n);

    vector<int> id;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        --u; --v;
        if (!used[u] && !used[v]) {
            used[u] = 1;
            used[v] = 1;
            id.push_back(i + 1);
        }

    }

    if (sz(id) >= n) {
        cout << "Matching" << endl;
        for (int i = 0; i < n; ++i) {
            cout << id[i] << " ";
        }
        cout << endl;
    } else {
        cout << "IndSet" << endl;
        int cnt = 0;
        for (int i = 0; i < 3 * n; ++i) {
            if (!used[i] && cnt < n) {
                ++cnt;
                cout << i + 1 << " ";
            }
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

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        solve();
    }
}