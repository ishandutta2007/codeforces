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


ll n, i, j, a, b, c, d;
vector<ll> m;
bool viv = false;

void check(vector<ll> ans) {
    for (ll i = 1; i < ans.size(); i++)
        if (abs(ans[i] - ans[i-1]) != 1)
            return;
    ll ma = a;
    ll mb = b;
    ll mc = c;
    ll md = d;
    for (auto i : ans) {
        if (i == 0)
            ma--;
        if (i == 1)
            mb--;
        if (i == 2)
            mc--;
        if (i == 3)
            md--;
    }
    if (ma || mb || mc || md)
        return;
    cout << "YES\n";
    for (auto i : ans)
        cout << i << ' ';
    exit(0);
}

void check(bool add_b, bool add_c, bool pb, bool pc) {
    ll lb = b;
    ll lc = c;
    vector<ll> s, f;
    if (add_b)
        s.push_back(1), lb--;
    for (ll i = 0; i < a; i++)
        s.push_back(0),
        s.push_back(1), lb--;
    if (pb && a == 0)
        return;
    if (pb)
        s.pop_back(), lb++;

    if (add_c)
        f.push_back(2), lc--;
    for (ll i = 0; i < d; i++)
        f.push_back(3),
        f.push_back(2), lc--;
    if (pc && d == 0)
        return;
    if (pc)
        f.pop_back(), lc++;

    if (viv) {
        cout << "Saw " << endl;
        for (auto i : s)
            cout << i << ' ';
        cout << endl;
        for (auto i : f)
            cout << i << ' ';
        cout << endl;
    }


    if (lc < 0 || lb < 0 || lc != lb)
        return;

    while (lc)
        s.push_back(2),
        s.push_back(1), lc--;

    reverse(f.begin(), f.end());
    for (auto i : f)
        s.push_back(i);
    check(s);
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> d;
    n = a + b + c + d;
    for (ll i = 0; i < 2; i++)
        for (ll j = 0; j < 2; j++)
            for (ll i1 = 0; i1 < 2; i1++)
                for (ll j1 = 0; j1 < 2; j1++)
            check(i, j, i1, j1);

    cout << "NO";

    return 0;
}