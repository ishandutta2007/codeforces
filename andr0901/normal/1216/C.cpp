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
#define x first
#define y second

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector <pii> a(6);
    vector <int> cords;
    forn (i, 0, 6) {
        cin >> a[i].x >> a[i].y;
        cords.pb(a[i].x), cords.pb(a[i].y);
    }
    sort(all(cords)), cords.erase(unique(all(cords)), cords.end());
    map <int, int> mp;
    forn (i, 0, sz(cords))
        mp[cords[i]] = i;
    forn (i, 0, 6) {
        a[i].x = mp[a[i].x], a[i].y = mp[a[i].y];
        //cout << a[i].x << " " << a[i].y << "\n";
    }
    vector <vector <int>> rec(20, vector <int> (20));
    forn (x, a[2].x, a[3].x)
        forn (y, a[2].y, a[3].y)
            rec[x][y] = 1;
    forn (x, a[4].x, a[5].x)
        forn (y, a[4].y, a[5].y)
            rec[x][y] = 1;
    /*forn (x, 0, 20)
        forn (y, 0, 20)
            cout << rec[x][y] << " \n"[y == 19];*/
    forn (x, a[0].x, a[1].x)
        forn (y, a[0].y, a[1].y)
            if (!rec[x][y])
                return cout << "YES", 0;
    cout << "NO";
    return 0;
}