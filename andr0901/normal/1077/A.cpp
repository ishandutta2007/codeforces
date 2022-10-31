#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        ll a, b, k;
        cin >> a >> b >> k;
        if (k % 2 == 0)
            cout << (a - b) * (k / 2);
        else
            cout << (a - b) * (k / 2) + a;
        cout << '\n';
    }
    return 0;
}