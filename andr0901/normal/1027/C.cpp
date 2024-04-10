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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        map <int, int> a;
        forn (i, 0, n) {
            int t;
            cin >> t;
            a[t]++;
        }
        vector <int> b;
        for (pii i : a) {
            if (i.sc > 3)
                b.pb(i.fs), b.pb(i.fs);
            else if (i.sc > 1)
                b.pb(i.fs);
        }
        sort(all(b));
        ll ans_p = 1e9, ans_q = 1, ans_a, ans_b;
        forn (i, 0, sz(b) - 1) 
            if ((b[i] * b[i] + b[i + 1] * b[i + 1]) * ans_q < b[i] * b[i + 1] * ans_p)
                ans_p = b[i] * b[i] + b[i + 1] * b[i + 1], ans_q = b[i] * b[i + 1], ans_a = b[i + 1], ans_b = b[i];
        cout << ans_a << " " << ans_a << " " << ans_b << " " <<  ans_b << "\n";
    }
    return 0;
}