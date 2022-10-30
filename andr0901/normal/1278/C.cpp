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

int n;

int solve(vector <int>& a, vector <int>& b) {
    int ans = 1e9;
    vector <int> suf(n + 1);
    for (int i = n - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + b[i];
    map <int, int> suf_to_i;
    forn (i, 0, n + 1)  {
        if (suf_to_i.find(suf[i]) == suf_to_i.end())
            suf_to_i[suf[i]] = 1e9;
        suf_to_i[suf[i]] = min(suf_to_i[suf[i]], i);
    }
    int bal = 0;
    forn (i, 0, n)
        bal += a[i];
    if (bal == -suf[0])
        return 0;
    forn (i, 0, n) {
        //cout << bal << " ";
        bal -= a[i];
        if (suf_to_i.find(-bal) != suf_to_i.end())
            ans = min(ans, suf_to_i[-bal] + i + 1);
    }
    //cout << "\n";
    return ans;
}

void solve() {
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    forn (i, 0, n) {
        cin >> a[i];
        if (a[i] == 2)
            a[i] = -1;
    }
    forn (i, 0, n) {
        cin >> b[i];
        if (b[i] == 2)
            b[i] = -1;
    }
    reverse(all(a));
    cout << min(solve(a, b), solve(b, a)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}