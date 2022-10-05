#include <bits/stdc++.h>

#pragma GCC optimize("O3", "unroll-all-loops")
#pragma GCC target("avx2")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const ld eps = 1e-7;

ll n, con;
vector<ld> mx, mn, sum;
bool viv = false;

ld read() {
    string s;
    cin >> s;
    if (s.size() == 1 || s[0] == '1') return s[0] - '0';
    s.erase(s.begin());
    s.erase(s.begin());
    s.resize(9, '0');
    ld ans = atoi(s.c_str());
    ans /= 1e9;
    return ans;
}

pld root(ld sa, ld sab, ld s, ld mx) {
//    ld sb = sab - sa;
    ld b = 2*sa - sab - s;
    ld c = mx - s * sa;
    cout.precision(20);
    ld d = sqrtl(max((ld)0, b * b - 4 * c));
//    ld d = sqrtl(max((ld)0, (sa - sb - s) * (sa - sb - s) - 4 * (mx - s * sa)));
    pld rs = {(- b + d) / 2, 0};
//    pld rs = {(- b + sqrtl(max((ld)0, (sa - sb - s) * (sa - sb - s) - 4 * (mx - s * sa)))) / 2, 0};
    rs.S = -b - rs.F;
    if (abs(rs.F) < eps)
        rs.F = 0;
    if (abs(rs.S) < eps)
        rs.S = 0;
    if (abs(rs.F - s) < eps)
        rs.F = s;
    if (abs(rs.S - s) < eps)
        rs.S = s;
    return rs;
}

void prepare() {
    sum = mn;
    for (ll i = 0; i < n; i++)
        sum[i] += mx[i];

    vector<ld> pref;
    pref.push_back(0);
    for (ll i = 0; i < n; i++)
        pref.push_back(pref.back() + sum[i]);

    ld suma = 0;
    vector<ld> a, b;
    for (ll i = 0; i < n; i++) {
        pld add = root(suma, pref[i], sum[i], mx[i]);
//        cout << add.F << ' ' << add.S << endl;
        if (viv)
            cout << "__ " << add.F << ' ' << add.S << endl;
        a.push_back(add.F);
        suma += a.back();
        if (a.back() < 0 || sum[i] - a.back() < 0) {
            suma -= a.back();
            a.pop_back();
            a.push_back(add.S);
            suma += a.back();
        }
        if (a.back() < 0 || sum[i] - a.back() < 0) {
            suma -= a.back();
            a.pop_back();
            a.push_back(0);
            suma += a.back();
        }
    }
    cout.precision(6);
    for (ll i = 0; i < n; i++)
        cout << fixed << a[i]<< ' ';
    cout << endl;
    for (ll i = 0; i < n; i++)
        cout << fixed << sum[i] - a[i] << ' ';
    cout << endl;
}

int main() {
//    freopen("ex.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
        mx.push_back(read());
    for (ll i = 0; i < n; i++)
        mn.push_back(read());
    prepare();






    return 0;
}
/**
10
0.10 0.02 0.04 0.69 0.01 0.01 0.06 0.02 0.03 0.02
1 0 0 0 0 0 0 0 0 0

3
0.07 0.2 0.73
0.73 0.2 0.07

3
0.02 0.22 0.76
0.28 0.58 0.14

6
0.001 0.0035 0.3843 0.11 0.1837 0.3175
0.109 0.0665 0.6957 0.07 0.0363 0.0225

10
0.00022404 0.00074752 0.00196930 0.00393592 0.00255606 0.00436464 0.00217638 0.00245083 0.00950300 0.97207230
0.03596096 0.02540748 0.04472470 0.05320308 0.02658194 0.03841636 0.01653562 0.01777117 0.05187200 0.68952670

**/