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
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(n);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        --x;
        v[x].push_back(i);
    }


    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].empty()) {
            ++res;
        }
    }

    for (int i = 0; i + 1 < n; ++i) {
        if (v[i].empty() || v[i + 1].empty()) {
            res += 2;
        } else {
            if (v[i][0] > v[i + 1].back()) {
                ++res;
            }
            if (v[i + 1][0] > v[i].back()) {
                ++res;
            }
        }
    }
    cout << res << endl;
}