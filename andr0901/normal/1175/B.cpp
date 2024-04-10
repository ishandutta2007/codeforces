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
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    vector <int> st, to_add;
    st.pb(1), to_add.pb(0);
    ll x = 0;
    int cur = 0;
    forn (i, 0, q) {
        string s;
        cin >> s;
        if (s[0] == 'a') 
            to_add.back()++;
        else if (s[0] == 'f') {
            int t;
            cin >> t;
            st.pb(t);
            to_add.pb(0);
        } else {
            int t = st.back() * to_add.back();
            st.pop_back();
            to_add.pop_back();
            to_add.back() += t;
            if (to_add.back() >= (1LL << 32))
                return cout << "OVERFLOW!!!", 0;
        }
    }
    int t = st.back() * to_add.back();
            if (t >= (1LL << 32))
                return cout << "OVERFLOW!!!", 0;
    cout << t;
    return 0;
}