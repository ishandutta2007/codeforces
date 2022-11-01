#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const int MOD = 1e9 + 7;

ll a[N], pref[N];
ll b[N], prefb[N];

int main() {
    int n, t;
    cin >> n;
    frab(i, 1, 1 + n)
        cin >> a[i];
    pref[0] = 0;
    frab(i, 1, n + 1)
        pref[i] = pref[i - 1] + a[i];
    frab(i, 1, 1 + n)
        b[i] = a[i];
    sort(b + 1, b + n + 1);
    frab(i, 1, n + 1)
        prefb[i] = prefb[i - 1] + b[i];
    int m, l, r;
    cin >> m;
    fr(i, m) {
        cin >> t >> l >> r;
        if (t == 1) {
            cout << pref[r] - pref[l - 1] << endl;
        }
        else
            cout << prefb[r] - prefb[l - 1] << endl;
    }
}