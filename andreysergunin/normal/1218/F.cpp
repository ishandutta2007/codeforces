#pragma GCC optimize("Ofast", "unroll-loops")

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

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;
using Complex = complex<double>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 100100;

int a[MAXN];
int c[MAXN];

int minn[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif  

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int boost;
    cin >> boost;

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }


    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > k) {
            minn[i] = (a[i] - k + boost - 1) / boost;
        }
    }

    int cur = 0;
    set<pii> setik;
    
    ll cost = 0;

    for (int i = 0; i < n; ++i) {
        setik.insert({c[i], i});
        while (sz(setik) > 0 && minn[i] > cur) {
            ++cur;
            auto it = setik.begin();
            cost += it->first;
            setik.erase(it);
        }

        if (minn[i] > cur) {
            cout << -1 << endl;
            return 0;
        }
    } 

    cout << cost << endl;

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}