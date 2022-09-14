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

ll m;

ll binPow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll x = binPow(a, b / 2);
    x *= x;
    x %= m;
    if (b & 1) {
        x *= a;
        x %= m;
    }
    return x;
}

const int op = 50;

int main() {
    // ifstream cin("input.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> m >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    if (n == m) {
        cout << 0 << " " << 1 << endl;
        return 0;
    }

    random_shuffle(all(a));

    if (n == 1) {
        cout << a[0] << " " << 0 << endl;
        return 0;
    }

    unordered_map<ll, bool> mp;
    for (int i = 0; i < n; ++i)
        mp[a[i]] = 1;

    vector<int> b;
    for (int i = 0; i < min(2 * n, m); ++i) {
        if (!mp.count(i))
            b.push_back(i);
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];
    sum %= m;
    ll x = binPow(n * (n - 1) / 2, m - 2);

    for (int i = 0; i < n; ++i) {
        if (!(i % 100)) {
            double tim = clock();
            tim /= CLOCKS_PER_SEC;
            if (tim >= 1.8) {
                cout << -1 << endl;
                return 0;
            }
        }
        ll tmp = n * x;
        tmp %= m;
        tmp *= a[i];
        ll d = x * sum - tmp;
        d %= m;
        if (d < 0)
            d += m;
        if (d == 0)
            continue;
        // cout << "!" << a[i] << " " << d << endl;

        ll r = binPow(d, m - 2);
        ll st = a[i] * r % m;
        // cout << st << endl;

        bool f = true;

        for (int j = 0; j < op; ++j) {
            ll k = rr() % n;
            ll cur = a[k] * r % m;
            ll t = cur - st;
            if (t < 0)
                t += m;

            if (t >= n) {
                f = false;
                break;
            }
        }

        for (int j = 0; j < op; ++j) {
            ll k = rr() % sz(b);
            ll cur = b[k] * r % m;
            ll t = cur - st;
            if (t < 0)
                t += m;

            if (t < n) {
                f = false;
                break;
            }
        }


        if (f) {
            for (int j = 0; j < n; ++j) {
                ll cur = a[j] * r % m;
                ll t = cur - st;
                if (t < 0)
                    t += m;
                if (t >= n) {
                    f = false;
                    break;
                }
            }

            if (f) {
                cout << a[i] << " " << d << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;


    return 0;
}