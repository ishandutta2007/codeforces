#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const ll MOD = 1e9 + 7;

ll a[N];
ll pref[N], suf[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    srand(time(NULL));
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    pref[0] = 1;
    frab(i, 1, n)
        if (a[i] > a[i - 1])
            pref[i] = pref[i - 1] + 1;
        else
            pref[i] = 1;
    suf[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        if (a[i] < a[i + 1])
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = 1;
    ll ans = 0;
//    fr(i, n)
//        cout << pref[i] << " ";cout << endl;
//    fr(i, n)
//        cout << suf[i] << " ";cout << endl;
    fr(i, n) {
        ans = max(max(ans, pref[i]), suf[i]);
        if (i != 0) ans = max(ans, 1 + suf[i]);
        if (i != n - 1) ans = max(ans, 1 + pref[i]);
        if (i - 1 >= 0 && i + 1 < n && a[i - 1] + 1 < a[i + 1])
            ans = max(ans, pref[i - 1] + suf[i + 1] + 1);
        if (i == 0)
            ans = max(ans, suf[1] + 1);
        if (i == n - 1)
            ans = max(ans, 1 + pref[n - 2]);
    }
    cout << ans;
}