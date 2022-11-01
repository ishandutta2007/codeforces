#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const int N = 1e5;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int MAX = 1e6;

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    freopen("a.in", "r", stdin);
    ll n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    ll cnt = accumulate(a, a + n, 0ll);
    if (cnt == 0) {
        cout << 0;
        return 0;
    }
    if (cnt == 1) {
        cout << 1;
        return 0;
    }
    ll cur = -1;
    while (a[cur + 1] == 0)
        cur++;
    ll cur2 = n;
    while (a[cur2 - 1] == 0)
        cur2--;
    vector <ll> c;
    ll curr = 1;
    frab(i, cur + 1, cur2) {
        if (a[i] == 0)
            curr++;
        else {
            c.pb(curr);
            curr = 1;
        }
    }
    ll ans = 1;
    fr(i, c.size())
        ans *= c[i];
    cout << ans;
    return 0;
}