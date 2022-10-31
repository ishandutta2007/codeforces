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

int nxt() {
    int x;
    cin >> x;
    return x;
}

string first = "Alice", second = "Bob";

void solve() {
    int n = nxt(), k = nxt();
    if (k % 3) {
        if (n % 3)
            cout << first << "\n";
        else 
            cout << second << "\n";
    } else {
        n %= (k + 1);
        if (n % 3 || n == k)
            cout << first << "\n";
        else 
            cout << second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = nxt();
    while (t --> 0)
        solve();
    return 0;
}