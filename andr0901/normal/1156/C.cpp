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

int n, z;
vector <int> a;

bool check(int m) {
    forn (i, 0, m) 
        if (a[n - m + i] - a[i] < z)
            return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> z;
    a.resize(n);
    forn (i, 0, n)
        cin >> a[i];
    sort(all(a));
    int l = 0, r = n / 2 + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (check(m))
            l = m;
        else 
            r = m;
    }
    cout << l;
    return 0;
}