#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int x;
    cin >> x;
    if (x == 1) {
        cout << -1;
        return 0;
    }
    cout << x << " " << x;
    return 0;
}