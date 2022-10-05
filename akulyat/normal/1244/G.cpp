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


ll n, i, j, ma, mi, k;
vector<ll> m, v;
bool viv = false;

ll res(vector<ll> a, vector<ll> b) {
    ll ans = 0;
    for (ll i = 0; i < a.size(); i++)
        ans += max(a[i], b[i]);
    return ans;
}

ll sans(ll val, vector<ll> a, vector<ll> b) {
    if (val != -1)
        val = res(a, b);
    cout << val << endl;
    if (val != -1) {
        for (auto i : a)
            cout << i << ' ';
        cout << endl;
        for (auto i : b)
            cout << i << ' ';
        cout << endl;
    }
    exit(0);
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        m.push_back(i + 1);
    v = m;
    mi = res(m, v);
    if (mi > k)
        sans(-1, {}, {});
    reverse(v.begin(), v.end());
    ma = res(m, v);
    if (ma <= k)
        sans(ma, m, v);

    if (viv)
        cout << "Smth smarter" << endl;

    ll nex = n;
    ll add = n - 1;
    ll left = k - mi;
    vector<ll> how;
    while (true) {
        ll can = min(left, add);
        if (viv)
            cout << "On this step " << can << endl;
        left -= can;
        if (left == 0) {
            ll adder = 1;
            ll pl = nex - can - 1;
            if (viv)
                cout << "Choose " << nex << " and put on " << pl << endl;
            for (ll i = 0; i < n; i++) {
                if (i == how.size()) {
                    if (i == pl)
                        how.push_back(nex);
                    else
                        how.push_back(adder), adder++;
                }
            }
            sans(0, m, how);
        }

        how.push_back(nex);
        add -= 2;
        nex--;
        if (viv) {
            cout << "Now: ";
            for (auto i : how)
                cout << i << ' ';
            cout << endl;
        }
    }






    return 0;
}