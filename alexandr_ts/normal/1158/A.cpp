#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const ll INF = 1e15 + 10;
const int LOG = 20;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

ll a[N];
ll b[N];

void solve() {
    ll n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    fr(i, m)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    if (a[n - 1] > b[0]) {
        cout << -1;
        return;
    }

    ll sum = accumulate(a, a + n, 0ll) * (ll)m;

    if (a[n - 1] == b[0]) {
        fr(j, m)
            sum += (b[j] - a[n - 1]);
        cout << sum;
        return;
    }

    sum += -(m - 1) * a[n - 1] - a[n - 2];
    fr(j, m)
        sum += b[j];
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}