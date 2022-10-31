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
#define int long long

vector <int> p;
int x, a, b, y, k;

bool check(int mid) {
    vector<int> revenue(mid);
    forn (i, 0, mid) {
        if ((i + 1) % a == 0)
            revenue[i] += x;
        if ((i + 1) % b == 0)
            revenue[i] += y;
    }
    sort(rall(revenue));
    int sum = 0;
    forn (i, 0, mid)
        sum += (p[i] * revenue[i]) / 100;
    return sum >= k;
}

void solve() {
    int n;
    cin >> n;
    p.clear();
    p.resize(n);
    forn (i, 0, n)  
        cin >> p[i];
    cin >> x >> a >> y >> b >> k;
    /*if (x < y)
        swap(x, y);*/
    sort(rall(p));
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (!check(mid))
            l = mid;
        else
            r = mid;
        //cout << l << " " << r << "\n";
    }
    //cout << ans1 << " " << ans2 << "\n";
    if (!check(r))
        cout << "-1\n";
    else 
        cout << r << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q --> 0)
        solve();
    return 0;
}