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
#define int long long
#define x first
#define y second

int dst(pii a, pii b) {
    return llabs(a.x - b.x) + llabs(a.y - b.y);
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    pii prev, a, b, st;
    int t;
    cin >> prev.x >> prev.y >> a.x >> a.y >> b.x >> b.y;
    cin >> st.x >> st.y >> t;
    vector <pii> points = {prev};
    while (prev.x < 3e16 && prev.y < 3e16) {
        points.eb(a.x * prev.x + b.x, a.y * prev.y + b.y);
        prev = points.back();
    }
    //cout << (((long long)3e16) * 100);
    int ans = 0;
    int n = points.size();
    forn (i, 0, n) {
        forn (l, 0, n) {
            forn (r, l, n) {    
                int cur = dst(points[i], st);
                bool ok = true;
                forn (j, min(l, i), max(l, i)) {
                    cur += dst(points[j], points[j + 1]);
                    if (cur > t)
                        ok = false;
                }
                forn (j, l, r) {
                    cur += dst(points[j], points[j + 1]);
                    if (cur > t)
                        ok = false;
                }
               // if (ok)
                 //   cout << cur << " ";
                if (cur <= t && ok) {
                    /*if (max({l, r, i}) - min({l, r, i}) + 1 > ans) {
                        //cout << i << " " << l << " " << r  << " " << cur << "\n";
                    }*/
                    ans = max(ans, max({l, r, i}) - min({l, r, i}) + 1);
                }
                cur = dst(points[i], st);
                ok = true;
                forn (j, min(i, r), max(i, r)) {
                    cur += dst(points[j], points[j + 1]);
                    if (cur > t)
                        ok = false;
                }
                forn (j, l, r){
                    cur += dst(points[j], points[j + 1]);
                    if (cur > t)
                        ok = false;
                }
                if (cur <= t && ok)
                    ans = max(ans, max({l, r, i}) - min({l, r, i}) + 1);
                //cout << cur << " ";
            }
        }
    }
    cout << ans;;
    return 0;
}