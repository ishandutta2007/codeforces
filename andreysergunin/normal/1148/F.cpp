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


    int n;
    cin >> n;
    vector<ll> mask(n), a(n);

    ll s = 0 ;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> mask[i];
        s += a[i];
    }

    if (s < 0) {
        for (int i = 0; i < n; ++i) {
            a[i] *= -1;
        }
        s *= -1;
    } 

    ll cur = 0;
    ll full = 0;



    for (int b = 0; b < 62; ++b) {
        ll e = 0;

        full |= (1ll << b);
        for (int i = 0; i < n; ++i) {
            if ((mask[i] & full) == mask[i]) {
                int x = __builtin_popcount(mask[i] & cur);
                if (x & 1) {
                    e -= a[i];
                } else {
                    e += a[i];
                }
            }
        }

        if (e > 0 || (e == 0 && cur != 0)) {
            cur |= (1ll << b);
        }
    }

    cout << cur << endl;

    // int ss = 0;
    // for (int i = 0; i < n; ++i) {
    //     if (__builtin_popcount(mask[i] & cur) & 1) {
    //         ss -= a[i];
    //     } else {
    //         ss += a[i];
    //     }
    // }

    // cout << ss << endl;

}