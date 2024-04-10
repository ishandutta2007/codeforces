#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 2 * 1e6;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

ll a[N];
vector <ll> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
//freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    ll mx = -INF;
    for (int i = n - 1; i >= 0; i--) {
        ans.pb(max(0ll, mx - a[i] + 1));
        mx = max(mx, a[i]);
    }
    reverse(ans.begin(), ans.end());
    fr(i, n)
        cout << ans[i] << " ";
}