#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void finish(const vector <pii>& ans) {
    cout << sz(ans) << "\n";
    for (auto i : ans)
        cout << i.fs + 1 << " " << i.sc + 1 << "\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> ans;
    forn (i, 0, n)
        ans.eb(i, (i + 1) % n);
    if (is_prime(sz(ans))) 
        finish(ans);
    vector <int> deg(n, 2);
    forn (i, 0, n) {
        if (deg[i] > 2)
            continue;
        ans.eb(i, (i + 2) % n);
        deg[i]++, deg[(i + 2) % n]++;
        if (is_prime(sz(ans))) 
            finish(ans);
    }
    return 0;
}