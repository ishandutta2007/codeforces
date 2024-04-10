// ToMo01's algorithm
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

ll powMod(ll a, ll p)
{
    ll res = 1;
    while (p > 0) {
        if (p & 1) res = res * a % MOD;
        p >>= 1;
        a = a * a % MOD;
    }
    return res;
}

int main()
{
    map<ll, ll> m;
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int tmp;
        cin >> tmp;
        if (m.find(tmp) == m.end()) m[tmp] = 1;
        else ++m[tmp];
    }
    vector< pair<ll, ll> > v;
    for (auto a : m) v.push_back(a);
    vector<ll> left(v.size()), right(v.size());
    left[0] = v[0].second + 1;
    for (int i = 1; i < v.size(); ++i) left[i] = left[i-1] * (v[i].second + 1) % (MOD - 1);
    right[v.size() - 1] = v[v.size() - 1].second + 1;
    for (int i = v.size() - 2; i >= 0; --i) right[i] = right[i+1] * (v[i].second + 1) % (MOD - 1);

    ll ans = 1;
    for (int i = 0; i < v.size(); ++i) {
        ll p = (v[i].second * (v[i].second + 1) >> 1) % (MOD - 1);
        if (i > 0) p = p * left[i-1] % (MOD - 1);
        if (i < v.size() - 1) p = p * right[i+1] % (MOD - 1);
        ans = ans * powMod(v[i].first, p) % MOD;
    }
    cout << ans << endl;
}