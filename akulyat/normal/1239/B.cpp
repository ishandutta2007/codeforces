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


ll n, i, j, sh, stans;
string s, s2;
vector<ll> o, c, ins, imin;
vector<pll> pr, mpr;
bool viv = false;

void check() {
    int dif = 0;
    for (auto i : s)
        if (i == '(')
            dif++;
        else
            dif--;
    if (dif) {
        cout << 0 <<  endl;
        cout << 1 << ' ' << 1 << endl;
        exit(0);
    }
}

void calc() {
    vector<bool> pref(n, false);
    vector<bool> suf(n, false);
    vector<ll> psum;
    vector<ll> ssum;
    psum.push_back(0);
    ssum.push_back(0);
    ll s_max = 0;
    ll p_max = 0;
    for (int i = 0; i < n; i++) {
        psum.push_back(psum.back());
        if (s[i] == '(')
            psum.back()--;
        else
            psum.back()++;
        p_max = max(p_max, psum.back());
        if (s[i] == ')' && p_max <= psum.back())
                pref[i] = true;
    }

    for (int i = n - 1; i >= 0; i--) {
        ssum.push_back(ssum.back());
        if (s[i] == ')')
            ssum.back()--;
        else
            ssum.back()++;
        s_max = max(s_max, ssum.back());
        if (s[i] == '(' && s_max <= ssum.back())
                suf[i] = true;
    }
    vector<bool> st(n, false);
    for (int i = 0; i < n; i++)
        if ((i == n-1 || suf[i]) && (i == 0 || pref[(i + n - 1)%n]))
            st[i] = true;
    if (viv) {
        for (auto i : pref)
            cout << i;
        cout << endl;
        for (auto i : suf)
            cout << i;
        cout << endl;
        for (auto i : st)
            cout << i;
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        if (st[i])
            sh = i, i = n;

    for (int i = 0; i < n; i++)
        s2 += s[(sh+i)%n];
}

void par() {
    vector<ll> st;
    o.resize(n, -1);
    c.resize(n, -1);
    ins.resize(n, 0);
    imin.resize(n, -1);
    for (int i = 0; i < n; i++) {
        if (s2[i] == '(')
            st.push_back(i);
        else {
            c[st.back()] = i;
            o[i] = st.back();
            st.pop_back();
            pr.push_back({o[i], i});
            if (st.empty())
                mpr.push_back({o[i], i});
            else {
                ins[st.back()]++;
                imin[o[i]] = st.back();
            }
        }
    }
    stans = mpr.size();
    if (stans == n/2) {
        cout << n/2 << endl;
        cout << 1 << ' ' << 1 << endl;
        exit(0);
    }
}

void solve() {
    if (viv)
        cout << s2 << endl;
    if (viv) {
        for (auto i : pr)
            cout << i.F << ' ' << i.S << "; ";
        cout << endl;
    }
    set <pll> st;
    vector<ll> stay(n, 0);
    vector<ll> add(n, 0);
    for (int i = 0; i < n; i++)
        if (c[i] != -1 && imin[i] != -1)
            stay[i] = stans;
    for (int i = 0; i < n; i++)
        if (c[i] != -1 && (imin[i] != -1 && imin[imin[i]] == -1 || imin[i] == -1))
            add[i] = ins[i];

    for (int i = 0; i < n; i++)
        if (c[i] != -1)
            st.insert({stay[i] + 1 + add[i], i});

    if (viv) {
        for (auto i : ins)
            cout << i << ' ';
        cout << endl;
    }

    auto ans = (*st.rbegin()).F;
    int op =(*st.rbegin()).S;

    cout << ans << endl;
    cout << (op + sh)%n + 1 << ' ' << (c[op] + sh)%n + 1 << endl;
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    check();
    calc();
    par();
    solve();








    return 0;
}
/**
30
(((((()()()()()()()()()())))))

10
(((()())))


*/