#include <bits/stdc++.h>


#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ll INF = 1e15 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;


void solve() {
    vector<int> perm = {4, 8, 15, 16, 23, 42};
    vector<int> ans(4, 0);

    for (int i = 2; i <= 5; i++) {
        cout << "? " << 1 << " " << i << endl;
        cin >> ans[i - 2];
    }

    do {
        bool ok = true;
        frab(i, 2, 6)
            if (perm[0] * perm[i - 1] != ans[i - 2])
                ok = false;
        if (ok) {
            cout << "! ";
            for (auto x: perm)
                cout << x << " ";
            cout << endl;
            return;
        }
    } while (next_permutation(perm.begin(), perm.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int t = 1;
    while (t--)
        solve();
}