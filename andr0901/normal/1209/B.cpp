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
    string used;
    cin >> used;
    forn (i, 0, n) 
        used[i] -= '0';
    vector <set <int>> lamps(n);
    forn (i, 0, n) {
        int a, b;
        cin >> a >> b;
        int cur = b;
        forn (j, 0, 1e4) {
            lamps[i].insert(cur);
            cur += a;
        }
    }
    int mx = 0;
    forn (i, 0, 1e4) {
        int cur = 0;
        forn (j, 0, n) 
            cur += used[j] == 1;
        mx = max(mx, cur);
        forn (j, 0, n) 
            if (lamps[j].find(i) != lamps[j].end())
                used[j] ^= 1;
    }
    cout << mx;
    return 0;
}