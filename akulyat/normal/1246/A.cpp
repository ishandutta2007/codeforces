#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j, p, ans;
vector<ll> m;
bool viv = false;

void check(ll n, ll k) {
    n -= k * p;
    ll wn = n;
    ll z = 0;
    while (n)
        z += (n&1), n /= 2;
    if (k <= wn && k >= z)
        ans = min(ans, k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> p;
    ans = inf;
    for (int i = 1; i < 5*ml; i++)
        check(n, i);
    if (ans == inf)
        ans = -1;
    cout << ans << endl;

    return 0;
}