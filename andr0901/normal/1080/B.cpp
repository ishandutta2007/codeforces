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
    int q;
    cin >> q;
    while (q --> 0) {
        int l, r;
        cin >> l >> r;
        int sgn;
        if (l % 2)
            sgn = -1;
        else
            sgn = 1;
        if (r % 2 != l % 2)
            cout << (-sgn) * (1 + (r - l) / 2);
        else
            cout << sgn * (l + (r - l) / 2);
        cout << "\n";
    }
    return 0;
}