#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define pb push_back
#define all(a) a.begin(),a.end()
#define foi(n) for (int i = 0; i < n; i++)
#define foj(n) for (int j = 0; j < n; j++)
#define fo(i, n) for (int i = 0; i < n; i++)
#define vei vector<int>
#define pii pair<int, int>
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

using namespace std;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    n *= 6;
    if (a * b >= n) {
        cout << a * b << endl << a << " " << b;
        return;
    }
    bool sw = a > b;
    if (sw) {
        swap(a, b);
    }
    ll mmin = (ll) 1e17;
    ll aa, ab;
    ll ob = b;
    for (; a * a <= n; a++) {
        b = (n + a - 1) / a;
        b = max(b, ob);
        if (a * b < mmin) {
            mmin = a * b;
            aa = a;
            ab = b;
        }
    }
    if (sw) {
        swap(aa, ab);
    }
    cout << mmin << endl << aa << " " << ab;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}