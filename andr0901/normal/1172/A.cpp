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

int n;
vector <int> b, where;

bool check(int m) {
    forn (i, 1, n + 1) {
        int pos = m + i - 1;
        if (where[i] > pos - n - 1) {
            //cout << m << ": " << i << " : bad\n";
            return 0;
        }
    }
    //cout << m << ": " << "good\n";
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    where.resize(n + 1);
    forn (i, 0, n) {
        int t;
        cin >> t;
        if (t)
            where[t] = -1;
    }
    b.resize(n);
    forn (i, 0, n) {
        int t;
        cin >> t;
        b[i] = t;
        if (t)
            where[t] = i;
    }
    forn (i, 0, n) {
        if (b[i] == 1) {
            bool ok = 1;
            forn (j, 2, n + 1) {
                int pos = i + j - 1;
                if (0 <= pos && pos < n) {
                    if (b[pos] == j)
                        continue;
                    else 
                        ok = 0;
                }
                if (where[j] > pos - n - 1) {
                    //cout << j << ": " << pos;
                    ok = 0;
                }
            }
            if (ok)
                return cout << i, 0;
        }
    }
    //forn (i, 1, n + 1) 
    //    cout << where[i] << " ";
    //cout << "\n";
    int l = n - 1, r =  2 *n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) 
            r = m;
        else 
            l = m;
    }
    cout << r;
    return 0;
}