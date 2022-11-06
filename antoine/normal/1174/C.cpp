#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


vector<pair<ll, int>> getFact(ll x) {
    assert(x > 0);
    vector<pair<ll, int>> v;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            v.emplace_back(i, 1);
            for (x /= i; x % i == 0; x /= i)
                v.back().second++;
        }
    if (x != 1)
        v.emplace_back(x, 1);

    return v;
}

void getDivisorsHelper(int i, ll curr, const vector<pair<ll, int>> &v, vector<ll> &res) {
    if (i == (int) v.size())
        res.push_back(curr);
    else {
        for (int j = 0; j <= v[i].second; ++j) {
            getDivisorsHelper(i + 1, curr, v, res);
            curr *= v[i].first;
        }
    }
}

vector<ll> getDivisors(const ll x) {
    const vector<pair<ll, int>> v = getFact(x);
    vector<ll> res;
    getDivisorsHelper(0, 1, v, res);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    map<int, int> mp;

    int n;
    cin >> n;
    for(int i = 2; i <= n; ++i) {
        vector<pair<ll, int>> fact = getFact(i);
        if(fact.size() == 1 && fact[0].second == 1) {
            int sz = (int)mp.size();
            mp[fact[0].first] = sz + 1;
        }
        cout << mp.at(fact[0].first) << ' ';
    }
    return 0;
}