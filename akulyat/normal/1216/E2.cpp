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
vector<ll> sum, lsum;
vector<ll> _len, _slen, _kol, sum_len, st_d;
bool viv = false;

void prepare() {
    _len.push_back(0);
    _slen.push_back(0);
    _kol.push_back(1);
    ll len = 1;
    ll slen = 0;
    ll kol = 9;
    sum.push_back(0);
    for (ll i = 0; i < 9; i++) {
        if (viv)
            cout << len << ' ' << slen << ' ' << kol << endl;
        _len.push_back(len);
        _slen.push_back(slen);
        _kol.push_back(kol);
        lsum.push_back(((slen + len + slen + len * (kol)) * kol ) / 2);
        sum.push_back(sum.back() + lsum.back());

        slen += len * kol;
        kol *= 10;
        len++;
    }

    if (viv) {
        for (auto i : sum)
            cout << i << ' ';
        cout << endl;
    }


    sum_len.push_back(0);
    for (ll i = 1; i < 9; i++)
        sum_len.push_back(sum_len.back() + _len[i] * _kol[i]);

    if (viv) {
        for (auto i : sum_len)
            cout << i << ' ';
        cout << endl;
    }

    st_d.push_back(1);
    for (ll i = 0; i < 9; i++)
        st_d.push_back(st_d.back() * 10);
}

ll lb(ll st, ll len, ll pl) {
    ll l = 0;
    ll r = 1;
    while ((((st + len) + (st + len * r)) * r) / 2 < pl)
        r <<= 1;
    while (l + 1 < r) {
        ll mi = l + r >> 1;
        if ((((st + len) + (st + len * mi)) * mi) / 2 < pl)
            l = mi;
        else
            r = mi;
    }
    return l;
}

vector<ll> dig(ll n) {
    vector<ll> res;
    while (n)
        res.push_back(n % 10), n /= 10;
    reverse(res.begin(), res.end());
    return res;
}

void show(ll n, ll k) {
    auto d = dig(n);
    if (viv) {
        cout << "Number " << n << endl;
        cout << "Digs decated: ";
        for (auto i : d)
            cout << i << ' ';
        cout << endl;
        cout << "want " << k << "-th " << endl;
    }
    cout << d[k-1] << '\n';
}

void easy(ll pl) {
    ll len = 0;
    while (sum_len[len + 1] < pl)
        len++;
    pl -= sum_len[len];
    len++;

    ll add = (pl - 1) / len;
    ll star = st_d[len - 1];
    star += add;
    pl -= add * len;
    show(star, pl);
}

void solve(ll pl) {
    ll len = 0;
    while (sum[len+1] < pl)
        len++;
    len++;

    if (viv) {
        cout << "len of piece is " << len << endl;
    }

    pl -= sum[len - 1];
    ll k = lb(_slen[len], _len[len], pl);
    if (viv) {
        cout << "skip " << k << " blocks" << endl;
    }
    pl -= (((_slen[len] + _len[len]) + (_slen[len] + _len[len] * k)) * k) / 2;

    if (viv) {
        cout << "want place " << pl << endl;
    }


    easy(pl);
}

int main() {
 //   viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prepare();
    ll q;
    cin >> q;
    while (q--) {
        ll pl;
        cin >> pl;
        solve(pl);
    }
    if (viv)
        for (ll i = 1; i < 100; i ++) {
            cout << i << ": ";
            solve(i);
        }





    return 0;
}