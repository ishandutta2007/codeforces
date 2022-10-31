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
    int n;
    cin >> n;
    vector <int> a(100, 1);
    forn (i, 0, n) {
        int k;
        cin >> k;
        vector <int> b(100);
        forn (j, 0, k) {
            int t;
            cin >> t;
            t--;
            b[t] = 1; 
        }
        forn (j, 0, 100)
            a[j] &= b[j];
    }
    forn (i, 0, 100) 
        if (a[i])
            cout << i + 1 << " ";
    return 0;
}