#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        cout << 0 << endl;
        return 0;
    }

    vector<ll> d;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            d.push_back(i);
            if (i * i != n)
               d.push_back(n / i);
        }
    }

    sort(all(d));

    if (sz(d) == 0) {
        cout << 1 << endl;
        cout << 0 << endl;
        return 0;
    }

    if ((sz(d) == 2 && d[0] * d[0] * d[0] != n) || sz(d) == 1) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
        if (n % (d[0] * d[0]) == 0) {
            cout << d[0] * d[0] << endl;
        } else {
            cout << d[0] * d[1] << endl;
        }
    }
        

    return 0;
}