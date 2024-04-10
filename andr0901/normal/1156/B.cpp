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
    int t;
    cin >> t;
    while (t --> 0) {
        string s;
        cin >> s;
        vector <int> a(26);
        forn (i, 0, sz(s))
            a[s[i] - 'a']++;
        int lst;
        forn (i, 0, sz(s))
            if (a[i])
                lst = i;
        vector <int> ans;           
        for (int i = 24; i >= 0; i -= 2) 
                forn (j, 0, a[i])
                    ans.pb(i);
            for (int i = 25; i >= 0; i -= 2)
                forn (j, 0, a[i])
                    ans.pb(i);
        bool ok = 1;
        forn (i, 1, sz(ans))
            if (abs(ans[i] - ans[i - 1]) == 1)
                ok = 0;
        if (ok) {
            forn (i, 0, sz(ans))
                cout << (char)(ans[i] + 'a');
            cout << "\n";
            continue;
        }
        ans.clear();
        for (int i = 25; i >= 0; i -= 2)
            forn (j, 0, a[i])
                ans.pb(i);
        for (int i = 24; i >= 0; i -= 2)
             forn (j, 0, a[i])
                ans.pb(i);
        ok = 1;
        forn (i, 1, sz(ans))
            if (abs(ans[i] - ans[i - 1]) == 1)
                ok = 0;
        if (!ok) {
            cout << "No answer\n";
            continue;
        }
        forn (i, 0, sz(ans))
            cout << (char)(ans[i] + 'a');
        cout << "\n";
    }
    return 0;
}