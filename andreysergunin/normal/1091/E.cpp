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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;
typedef pair<ll, int> pli;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vector<ll> d(n);

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    sort(all(d));
    reverse(all(d));

    ll l = 0, r = n;

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += d[i];
    }

    ll x = sum, y = 0;

    ll j = 0;

    for (ll k = n; k >= 1; --k) {
        // cout << k << " " << x << " " << y << endl;
        ll a = x - y - k * (k - 1);
        // cout << a << endl;
        if (a > k) {
            cout << -1 << endl;
            return 0;
        }

        l = max(l, a);

        x -= d[k - 1];

        while (j < n && d[j] > k - 1) {
            ++j;
        }
        y += min(d[k - 1], k);

        ll b = k * (k - 1) + y - x;
        // cout << b << endl;
        r = min(r, b);

        y -= max(0ll, j - k + 1);
    }

    vector<int> res;

    for (ll i = l; i <= r; ++i) {
        if ((i + sum) % 2 == 0) {
            res.push_back(i);
        }
    }

    if (sz(res) == 0) {
        cout << -1 << endl;
    } else {
        for (int el : res) {
            cout << el << " ";
        }
        cout << endl;
    }




}