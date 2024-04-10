#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e3 + 10;
const ll MOD = 1e9 + 7;

int a[N][N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    int cur = 1;
    fr(j, k - 1)
        fr(i, n)
            a[i][j] = cur++;
    fr(i, n)
        frab(j, k - 1, n)
            a[i][j] = cur++;

    int ans = 0;
    fr(i, n)
        ans += a[i][k - 1];
    cout << ans << endl;
    fr(i, n) {
        fr(j, n)
            cout << a[i][j] << " ";cout << endl;}

}