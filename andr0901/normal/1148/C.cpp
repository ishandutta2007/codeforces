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

vector <int> a, where;
vector <pii> ans;

void swp(int i, int j) {
    swap(a[i], a[j]);
    swap(where[a[i]], where[a[j]]);
    ans.eb(i, j);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a = where = vector <int> (n);
    forn (i, 0, n) {
        cin >> a[i], a[i]--;
        where[a[i]] = i;
    }
    forn (i, 0, n - 1) {
        if (i == where[i])
            continue;
        if (where[i] - i >= n / 2) {
            swp(i, where[i]);
        } else {
            int tf = -1, tb = -1;
            if (i < n / 2) {
                if (n - 1 - where[i] >= n / 2) 
                    swp(where[i], n - 1);
                else {
                    tf = where[i];
                    swp(where[i], 0);
                    swp(0, n - 1);
                }
                swp(i, where[i]);
                if (tf != -1)
                    swp(0, tf);
            } else {
                tb = where[i];
                swp(0, where[i]);
                swp(where[i], i);
                swp(0, tb);
            }
        }
    }
    cout << sz(ans) << "\n";
    for (pii i : ans)
        cout << i.fs + 1 << " " << i.sc + 1 << "\n";
    return 0;
}