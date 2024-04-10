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
    int n;
    cin >> n;
    vector <char> a(n);
    int bal = 0;
    int last_idx = -1;
    forn (i, 0, n) {
        cin >> a[i];
        if (a[i] == '(')
            bal++;
        else 
            bal--;
        if (bal < -1)
            return cout << "No", 0;
        if (bal == -1) 
            last_idx = i;
    }
    if (bal)
        return cout << "No", 0;
    if (last_idx == -1)
        return cout << "Yes", 0;
    forn (i, last_idx, n)
        if (a[i] == '(')
            return cout << "Yes", 0;
    cout << "No";
    return 0;
}