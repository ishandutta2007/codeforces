#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

char ch1[N], ch2[N];
string s[N], t[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll t, n, a, b, k;
    cin >> t >> n >> a >> b >> k;
    ll p = (n + 1) / 2;
    ll q = n / 2;
    ll tl = 0, tr = t + 1;
    while (tr - tl > 1) {
        ll tm = (tl + tr) / 2;
        bool ok = true;
        if (tm * k > a * p + b * q)
            ok = false;
        if (k > n)
            ok = false;
        if (k > p && tm * (k - p) > b * q)
            ok = false;
        if (k > q && tm * (k - q) > a * p)
            ok = false;
        if (ok)
            tl = tm;
        else
            tr = tm;
    }
    cout << tl;
}