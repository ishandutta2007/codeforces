#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;

const int N = 1e5 + 10;

ll cnt(ll x) {
    ll d = sqrt(x);
    while ((d + 1) * (d + 1) <= x) d++;
    while (d * d > x) d--;
    ll res = d;
    while (d * (d + 1) > x) d--;
    res += d;
    while (d * (d + 2) > x) d--;
    res += d;
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        cout << cnt(r) - cnt(l - 1) << "\n";
    }
    return 0;
}