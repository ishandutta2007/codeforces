#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
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
    int n, m;
    cin >> n >> m;
    if (n < 3) {
        if (m == 0) {
            forn (i, 7, 7 + n)
                cout << i << " ";
            return 0;
        } else {
            cout << "-1";
            return 0;
        }
    }
    vector <int> a(n, -1);
    a[0] = 1, a[1] = 2;
    forn (i, 2, n) {
        if (m <= (i - 1) / 2) {
            //cout << i << " kek";
            map <int, int> mp;
            forn (j, 0, i)
                forn (k, j + 1, i)
                    mp[a[j] + a[k]]++;
            for (auto j : mp) 
                if (j.fs > a[i - 1] && j.sc == m) {
                    a[i] = j.fs;
                    break;
                }
            m = 0;
            break;
        } else {
            a[i] = i + 1;
            m -= (a[i] - 1) / 2;
        }
    }
    if (m != 0) {
        cout << "-1";
        return 0;
    }
    int cur = 1e9;
    for (int i = n - 1; i >= 0; --i)
        if (a[i] == -1) {
            a[i] = cur;
            cur -= 6000;
        }
    for (int i : a)
        cout << i << " ";
    return 0;
}