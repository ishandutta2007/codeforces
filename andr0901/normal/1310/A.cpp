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
    int n;
    cin >> n;
    map <int, vector <int>> events;
    vector <pii> a(n);
    int prev = 1e9;
    forn (i, 0, n) {
        cin >> a[i].fs;
        prev = min(prev, a[i].fs);
    }
    forn (i, 0, n)
        cin >> a[i].sc;
    forn (i, 0, n)
        events[a[i].fs].pb(a[i].sc);
    long long sum = 0, ans = 0;
    multiset <int> cur;
    for (auto& [idx, b] : events) {
        forn (i, 0, idx - prev) {
            if (cur.empty())
                break;
            ans += 1LL * i * (*cur.rbegin());
            sum -= (*cur.rbegin());
            cur.erase(--cur.end());
        }
        ans += (idx - prev) * sum;

        for (int j : b) {
            cur.insert(j);
            sum += j;
        }
        prev = idx;

        /*for (int j : cur)
            cout << j << " ";
        cout << "\n" << ans << "\n";
        cout << "\n";*/
    }
    
    int i = 0;
    while (!cur.empty()) {
        ans += 1LL * i * (*cur.rbegin());
        sum -= (*cur.rbegin());
        cur.erase(--cur.end());
        ++i;
    }

    cout << ans;
    return 0;
}