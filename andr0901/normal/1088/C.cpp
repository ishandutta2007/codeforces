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
    int n;
    cin >> n;
    vector <ll> a(n);
    forn (i, 0, n)
        cin >> a[i];
    cout << n + 1 << "\n";
    for (int i = n - 1; i > -1; i--) {
        cout << "1 " << i + 1 << " " << (n + i - a[i] % n) % n << "\n";
        forn (j, 0, i)
            a[j] += (n + i - a[i] % n) % n;
    }
    cout << "2 " << n << " " << n;
    return 0;
}