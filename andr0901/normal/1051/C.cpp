#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <vector <int>> b(101);
    forn (i, 0, n)
        b[a[i]].pb(i);
    /*forn (i, 0, 10) {
        for (auto j : b[i])
            cout << j << " ";
        cout << "\n";
    }*/
    vector <int> ans(n);
    bool f = 0;
    forn (i, 0, 101) {
        if (b[i].size() == 1) {
            if (!f) {
                ans[b[i][0]] = 1;
                f ^= 1;
            } else {
                ans[b[i][0]] = 2;
                f ^= 1;
            }
            b[i].pop_back();
        }
    }
    if (f) {
        bool ff = 1;
        forn (i, 0, 101) {
            if (b[i].size() > 2) {
                ans[b[i].back()] = 2;
                b[i].pop_back();
                while (b[i].size()) {
                    ans[b[i].back()] = 1;
                    b[i].pop_back();
                }
                ff = 0;
                break;
            }
        }
        if (ff)
            return cout << "NO", 0;
    }
    forn (i, 0, 101) {
        if (b[i].size() == 2) {
            //cout << i << " ";
            //cout << b[i].back() << " ";
            ans[b[i].back()] = 1;
            b[i].pop_back();
            ans[b[i].back()] = 1;
            b[i].pop_back();
        }
    }
    /*cout << "YES\n";
    forn (i, 0, n)
        cout << ans[i] << " ";
    return 0;*/
    forn (i, 0, 101) {
        while (b[i].size()) {
            ans[b[i].back()] = 1;
            b[i].pop_back();
        }
    }
    cout << "YES\n";
    forn (i, 0, n) {
        if (ans[i] == 1)
            cout << 'A';
        if (ans[i] == 2)
            cout << 'B';
    }
    return 0;
}