#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

int nxt() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    string s, t, p;
    cin >> s >> t >> p;
    multiset <char> a;
    for (char i : p)
        a.insert(i);
    string new_s;
    int i = 0;
    forn (j, 0, sz(t)) {
        if (s[i] == t[j]) {
            i++;
            new_s += t[j];
        } else {
            if (a.find(t[j]) != a.end()) {
                a.erase(a.find(t[j]));
                new_s += t[j];
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    while (i < sz(s))
        new_s += s[i++];
    if (new_s == t)
        cout << "YES\n";
    else 
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q = nxt();
    while (q --> 0)
        solve();
    return 0;
}