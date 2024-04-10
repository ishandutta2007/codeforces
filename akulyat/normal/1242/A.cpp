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


ll n, i, j;
vector<ll> m;
bool viv = false;

long long GCD(long long a, long long b)
{
if (a == 0 && b == 0)
    return 1;
while (a != 0&&b != 0)
    {
    if (a >= b)
        a %= b;
    else
        b %= a;
    }
return a + b;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<ll> a, b;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
            if (i * i != n)
                b.push_back(n / i);
        }
    }
    while (b.size())
        a.push_back(b.back()), b.pop_back();

    for (ll i = 1; i < a.size(); i++) {
        if (GCD(a[i], a[i-1]) != a[i-1]) {
            cout << 1 << endl;
            return 0;
        }
    }
    if (a.empty()) {
        cout << n << endl;
        return 0;
    }
    cout << n / a.back();







    return 0;
}