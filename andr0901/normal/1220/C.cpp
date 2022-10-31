#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    map <char, bool> used;
    forn (i, 0, sz(s)) {
        bool ok = 0;
        forn (j, 'a', s[i])
            if (used[j])
                ok = 1;
        if (ok)
            cout << "Ann\n";
        else 
            cout << "Mike\n";
        used[s[i]] = true;
    }
    return 0;
}