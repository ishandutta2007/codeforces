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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    vector <int> b = {4, 8, 15, 16, 23, 42};
    vector <int> c(7);
    c[0] = 5e5;
    forn (i, 0, n) 
        forn (j, 0, 6) 
            if (a[i] == b[j] && c[j])
                c[j + 1]++, c[j]--;
    cout << n - c[6] * 6;
    return 0;
}