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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n), where(n + 1);
    forn (i, 0, n) 
        cin >> a[i], where[a[i]] = i;
    vector <int> l(n, -1), r(n, n);
    vector <int> st;
    forn (i, 0, n) {
        while (!st.empty() && a[i] > a[st.back()]) {
            r[st.back()] = i;
            st.pop_back();
        }
        st.pb(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[i] > a[st.back()]) {
            l[st.back()] = i;
            st.pop_back();
        }
        st.pb(i);
    }
    ll ans = 0;
    forn (i, 0, n) {
        if (i - l[i] <= r[i] - i) {
            forn (j, l[i] + 1, i) 
                if (i < where[a[i] - a[j]] && where[a[i] - a[j]] < r[i])
                    ans++;
        } else {
            forn (j, i + 1, r[i]) 
                if (l[i] < where[a[i] - a[j]] && where[a[i] - a[j]] < i)
                    ans++;
        }
    }
    cout << ans;
    return 0;
}