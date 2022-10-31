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

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int n, x;
    cin >> n >> x;
    set <int> a, b;
    vector <int> ans;
    int cur = 0;
    a.insert(0), b.insert(x);
    while (true) {
        bool ok = 0;
        forn (j, 1, 1 << n) {
            int t = (cur ^ j);
            if (a.find(t) == a.end() && b.find(t) == b.end()) {
                ok = 1;
                a.insert(t), b.insert(t ^ x);
                cur ^= j;
                ans.pb(j);
                break;
            }
        }
        if (!ok)
            break;
    }
    cout << sz(ans) << "\n";
    for (int i : ans)
        cout << i << " ";
    return 0;
}