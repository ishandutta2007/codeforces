#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, x, y;
    cin >> n >> x >> y;
    if (x + y <= n + 1)
        cout << "White";
    else
        cout << "Black";
    return 0;
}