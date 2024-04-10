#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

typedef __int128_t ll;

ll gcd(ll a, ll b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}


vector<vector<ll>> ops;
set<ll> have;

void add(ll a, ll b) {
    if (!have.count(a + b)) {
        ops.push_back({0, a, b});
        have.insert(a + b);
    }
}

void xorr(ll a, ll b) {
    if (!have.count(a ^ b)) {
        ops.push_back({1, a, b});
        have.insert(a ^ b);
    }
}

void mul(ll a, ll b) {
    ll ans = 0;
    while (b) {
        if (b % 2 == 1) {
            add(ans, a);
            ans += a;
        }
        b >>= 1;
        add(a, a);
        a *= 2;
    }
}

pair<ll, ll> ext_gcd(ll a, ll b) {
    if (a == 0) {
        return {0, 1};
    }
    auto pp = ext_gcd(b % a, a);
    ll x = pp.first;
    ll y = pp.second;
    return {y - (b / a) * x, x};
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int X;
    cin >> X;
    ll x = X;
    xorr(x, x);
    ll j = 1;
    while (gcd(2 * x, (x * j) ^ x) != 1 || ((x * j) ^ x) <= 2 * x) {
        j++;
    }
    mul(x, j);
    xorr((x * j), x);
    add(x, x);
    ll a = 2 * x;
    ll b = (x * j) ^ x;
    auto pp = ext_gcd(b, a);
    pp.first %= a;
    pp.first += a;
    pp.first %= a;
    pp.second = (1 - b * pp.first) / a;
    assert(pp.first * b + pp.second * a == 1);
    pp.second *= -1;
    assert(pp.first > 0);
    assert(pp.second > 0);
    mul(b, pp.first);
    mul(a, pp.second);
    xorr(b * pp.first, a * pp.second);
    assert(have.count(1));
    cout << ops.size() << endl;
    for (auto &op : ops) {
        int z;
        z = op[1];
        cout << z;
        cout << ' ';
        if (op[0] == 0) {
            cout << '+'; 
        } else {
            cout << '^';
        }
        cout << ' ';
        z = op[2];
        cout << z;
        cout << endl;
    }
    /*  for (int i = 3; i < 1000000; i += 2) {
        bool good = false;
        for (int j = 1; j < 1000000; j++) {
            if (gcd(2 * i, (i * j) ^ i) == 1 && ((i * j) ^ i) > 2 * i) {
                good = 1;
                break;
            }
        }
        if (gcd(i, (i * i) ^ i) == 1) {
            good = 1;
        }
        if (!good) {
            cout << i << endl;
            break;
        }
    }*/
}