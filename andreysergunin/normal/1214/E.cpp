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
default_random_engine generator;
// mt19937 rnd(1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif

    int n;
    cin >> n;

    vector<pii> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i].first;
        d[i].second = i;
    }

    sort(all(d));
    reverse(all(d));


    vector<int> chain;

    for (int i = 0; i < n; ++i) {
        chain.push_back(2 * d[i].second);

    }
    vector<pii> e;
    for (int i = 0; i < n - 1; ++i) {
        e.push_back({chain[i], chain[i + 1]});
    }

    for (int i = 0; i < n; ++i) {
        if (i + d[i].first == sz(chain)) {
            int u = chain.back();
            int v = 2 * d[i].second + 1;
            chain.push_back(v);
            e.push_back({u, v});
        } else {
            int u = chain[i + d[i].first - 1];
            int v = 2 * d[i].second + 1;
            e.push_back({u, v});
        }
    }

    for (pii el : e) {
        cout << el.first + 1 << " " << el.second + 1 << endl;
    }


#ifdef LOCAL
    cerr << "Time: " << ld(clock()) / CLOCKS_PER_SEC << endl;
#endif
}