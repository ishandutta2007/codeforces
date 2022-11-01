#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e3 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

ll a[N][N], b[N][N];
bool used[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    frab(i, 2, MAX)
        if (!used[i])
            for (ll j = 2 * i; j < MAX; j += i)
                used[j] = true;
    used[0] = used[1] = true;
    ll n, m;
    cin >> n >> m;
    fr(i, n)
        fr(j, m) {
            cin >> a[i][j];
            frab(k, a[i][j], MAX)
                if (!used[k]) {
                    b[i][j] = k - a[i][j];
                    break;
                }
        }
    ll ans = INF;
    fr(i, n)
        ans = min(ans, accumulate(b[i], b[i] + m, 0ll));
    fr(j, m) {
        ll sum = 0;
        fr(i, n)
            sum += b[i][j];
        ans = min(ans, sum);
    }
    cout << ans;

}