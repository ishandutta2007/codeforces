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


ll n, i, j, sh, k;
vector<ll> m;
bool viv = false;
string s;


void star() {
    ll q = -1;
    for (ll i = 0; i < n; i++)
        if (m[i] == m[(i + 1) % n])
            q = i;
    if (q == -1) {
        if (k & 1)
            for (auto &i : s)
                if (i == 'B')
                    i = 'W';
                else
                    i = 'B';
        cout << s << endl;
        exit(0);
    }
    q++;
    q %= n;
    sh = q;
    vector<ll> t;
    for (ll i = 0; i < n; i++)
        t.push_back(m[(i + sh) % n]);
    m = t;
}

void solve() {
    vector<ll> al;
    for (ll i = 0; i < n; i ++) {
        if (i > 0 && i < n - 1 && m[i] != m[i-1] && m[i] != m[i+1])
            al.push_back(true);
        else
            al.push_back(false);
    }
    vector<ll> l, r;
    l = al;
    r = al;
    for (ll i = 1; i < n; i++)
        if (l[i])
            l[i] += l[i-1];
    for (ll i = n - 2; i >= 0; i--)
        if (r[i])
            r[i] += r[i+1];
    for (ll i = 0; i < n; i++)
        l[i] = min(l[i], r[i]);

    vector<ll> ans = m;
    for (ll i = 0; i < n; i++) {
        if (l[i] <= k) {
            if (l[i] & 1)
                ans[i] = 1 - ans[i];
        } else
            if (k & 1)
                ans[i] = 1 - ans[i];
    }

    vector<ll> t;
    for (ll i = 0; i < n; i++) {
        t.push_back(ans[(i + n - sh) % n]);
    }
    ans = t;
    for (auto i : ans)
        if (i)
            cout << 'B';
    else
            cout << 'W';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> s;
    for (i = 0; i < n; i++) {
        ll a;
        a = s[i] == 'B';
        m.push_back(a);
    }
    star();
    solve();

    return 0;
}
/**
9 101
BWBWBWBWB

**/