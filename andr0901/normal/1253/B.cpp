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
    set <int> a;
    int prev = -1;
    vector <int> ans;
    forn (i, 0, n) {
        int x;
        cin >> x;
        if (x > 0) {
            if (a.find(x) != a.end() || a.find(-x) != a.end()) {
                cout << -1;
                return 0;
            } 
            a.insert(x);
        } else {
            if (a.find(-x) == a.end()) {
                cout << -1;
                return 0;
            } else {
                a.erase(-x);
                a.insert(x);
            }
        }
        if (a.lower_bound(0) == a.end()) {
            ans.pb(i - prev);
            prev += ans.back();
            a.clear();
            //cout << "ans" << i << "\n";
        }
        //cout << prev << " ";
        /*for (int i : a)
            cout << i << " ";
        cout << "\n";*/
    }
    if (a.lower_bound(0) == a.end()) {
        cout << ans.size() << "\n";
        for (int i : ans)
            cout << i  << " ";
    } else {
        cout << -1;
    }
    return 0;
}