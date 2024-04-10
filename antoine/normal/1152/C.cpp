#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


vector<pair<ll, int>> getFact(ll x) {
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

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0;
        return 0;
    }

    pair<ll, int> ans = {numeric_limits<ll>::max(), numeric_limits<int>::max()};

    for(const int d : getDivisors(abs(a-b))) {
        const int k = d * ((a + d - 1) / d) - a;
        ans = min(ans, {1LL * (a + k) * (b + k) / d, k});
    }


    cout << ans.second;


    return 0;
}