#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

void add(vector <int>& a, vector <int>& b) {
    a.resize(max(sz(a), sz(b)));
    int carry = 0;
    for (int i = 0; i < max(sz(a), sz(b)) || carry; i++) {
        if (i == sz(a))
            a.pb(0);
        a[i] += carry;
        if (i < sz(b))
            a[i] += b[i];
        carry = (a[i] > 9);
        if (carry)
            a[i] -= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    vector <int> b;
    forn (i, (n + 1) / 2, n) {
        if (a[i]) {
            for (int j = i - 1; j >= 0; j--)
                b.pb(a[j]);
            vector <int> c;
            for (int j = n - 1; j >= i; j--)
                c.pb(a[j]);
            add(b, c);
            //cout << i << "\n";
            break;
        }
    }
    vector <int> d;
    for (int i = n / 2; i > 0; i--) {
        if (a[i]) {
            for (int j = i - 1; j >= 0; j--)
                d.pb(a[j]);
            vector <int> e;
            for (int j = n - 1; j >= i; j--)
                e.pb(a[j]);
            add(d, e);
            //cout << i << "\n";
            break;
        }
    }
    bool ok1 = 1, ok2 = 1;
    if (b.empty())
        ok2 = 0;
    if (d.empty())
        ok1 = 0;
    string B, D;
    while (!b.empty()) {
        B += (char)(b.back() + '0');
        b.pop_back();
    }
    while (!d.empty()) {
        D += (char)(d.back() + '0');
        d.pop_back();
    }
    //cout << ok1 << " " << ok2 << "\n" << B << " " << D << "\n";
    if (!ok1)
        return cout << B, 0;
    if (!ok2)
        return cout << D, 0; 
    if (sz(B) < sz(D))
        return cout << B, 0;
    if (sz(D) < sz(B))
        return cout << D, 0;
    if (B < D) 
        cout << B;
    else
        cout << D;
    return 0;
}