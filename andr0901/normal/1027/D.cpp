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

vector <int> a, to, path, used;
ll ans = 0;

void find_cycles(int v) {
    if (used[v] == 2)
        return;
    if (used[v] == 1) {
        int cur = 1e9;
        while (true) {
            cur = min(cur, a[path.back()]);
            if (path.back() == v) 
                break;
            path.pop_back();
        } 
        ans += cur;
        return;
    } 
    used[v] = 1;
    path.pb(v);
    find_cycles(to[v]);
    used[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a = to = used = vector <int> (n);
    forn (i, 0, n) 
        cin >> a[i];
    forn (i, 0, n)
        cin >> to[i], to[i]--;
    forn (i, 0, n) {
        if (!used[i]) {
            path.clear();
            find_cycles(i);
        }
    }
    cout << ans;
    return 0;
}