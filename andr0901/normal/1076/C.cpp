#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n --> 0) {
        double d;
        cin >> d;
        d *= 1.0;
        if (d * d - 4 * d < 0)
            cout << "N\n";
        else
            cout << fixed << setprecision(9) << "Y " << (d + sqrt(d * d - 4 * d)) / 2 << " " << (d - sqrt(d * d - 4 * d)) / 2 << "\n";
    }
    return 0;
}