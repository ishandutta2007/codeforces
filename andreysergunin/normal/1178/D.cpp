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

const int P = 998244353;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int m = n + n / 2;
    vector<int> p(m + 1);
    for (int i = 2; i <= m; ++i) {
        if (p[i]) {
            continue;
        }
        for (int j = i; i * j <= m; ++j) {
            p[i * j] = 1;
        }
    }

    // bool ok = false;
    for (int i = n; i <= n + n / 2; ++i) {
        if (!p[i]) {
            cout << i << endl;

            for (int j = 0; j < n; ++j) {
                int u = j;
                int v = (j + 1) % n;
                cout << u + 1 << " " << v + 1 << endl;
            }

            for (int j = n; j < i; ++j) {
                int u = j - n;
                int v = u + n / 2;
                cout << u + 1 << " " << v + 1 << endl;
            }

            return 0;
        }
    }

    assert(false);

    return 0;
}