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
ll v1, v2;
vector<ll> u, d;
bool viv = false;

bool vec(ll a, ll b, ll c)  {
    a++, b++, c++;
    cout << 2 << ' ' << a << ' ' << b << ' ' << c << endl;
    ll res;
    cin >> res;
    return res == 1;
}

ll sq(ll a, ll b, ll c) {
    a++, b++, c++;
    cout << 1 << ' ' << a << ' ' << b << ' ' << c << endl;
    ll res;
    cin >> res;
    return res;
}

void good(vector<ll> &ans) {
    for (ll i = 0; i < n; i++)
        ans.push_back(ans[i]);
    vector<ll> rans;
    ll j = 0;
    while (ans[j] != 0)
        j++;
    for (ll i = j; i < j + n; i++)
        rans.push_back(ans[i]);
    ans = rans;
}

void norm(vector<ll> &vecc, bool xr) {
    if (vecc.empty())
        return;

    vector<pll> tos;
    for (auto i : vecc)
        tos.push_back({sq(i, v1, v2), i});
    sort(tos.begin(), tos.end());
    ll mid = tos.back().S;
    tos.pop_back();

    vector<ll> bef, aft;

    ll vv = v1;
    if (xr)
        vv = v2;
    for (auto i : tos) {
        if (vec(vv, i.S, mid))
            bef.push_back(i.S);
        else
            aft.push_back(i.S);
    }
        reverse(aft.begin(), aft.end());
    bef.push_back(mid);
    for (auto i : aft)
        bef.push_back(i);
    vecc = bef;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    v1 = n - 1;
    v2 = n - 2;


    for (ll i = 0 ; i < n - 2; i++) {
        if (vec(v1, i, v2))
            d.push_back(i);
        else
            u.push_back(i);
    }

    norm(d, 0);
    norm(u, 1);


    vector<ll> ans;
    ans.push_back(v1);
    for (auto i : d)
        ans.push_back(i);
    ans.push_back(v2);
    for (auto i : u)
        ans.push_back(i);

    if (!vec(ans[0], ans[1], ans[2]))
        reverse(ans.begin(), ans.end());

    cout << 0 << ' ';
    good(ans);
    for (auto i : ans)
        cout << i + 1 << ' ';



    return 0;
}