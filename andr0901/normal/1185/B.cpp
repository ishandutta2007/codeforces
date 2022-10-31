#pragma GCC optimize("Ofast")
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

vector <pii> compress(const string& s) {
    //cout << s << ": \n";
    vector <pii> ans;
    forn (i, 0, sz(s)) {
        int j = i;
        while (j < sz(s) && s[i] == s[j])
            j++;
        ans.eb(s[i], j - i);
        //cout << s[i] << " " << j - i << "\n";
        i = j - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n --> 0) {
        string s, t;
        cin >> s >> t;
        vector <pii> a = compress(s), b = compress(t);
        if (sz(a) != sz(b)) {
            cout << "NO\n";
            continue;
        }
        bool ok = 1;
        forn (i, 0, sz(a)) {
            if (a[i].fs != b[i].fs)
                ok = 0;
            if (a[i].fs == b[i].fs && a[i].sc > b[i].sc)
                ok = 0;
        }
        if (ok)
            cout << "YES";
        else 
            cout << "NO";
        cout << "\n";
    }
    return 0;
}