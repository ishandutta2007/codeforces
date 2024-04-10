#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e3 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int main() {
    ll n, t;
    cin >> n;
    map <ll, ll> m;
    fr(i, n) {
        cin >> t;
        m[t]++;
    }
    ll ans = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->first == 0)
            ans += (it->second * (it->second - 1));
        else
            ans += (it->second) * m[-(it->first)];
    }
    cout << ans / 2;
}