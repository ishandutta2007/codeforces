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
const ll N = 1e2 + 2;
const ld EPS = 1e-8;

ll c[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    fr(i, 101)
        fr(j, 101)
            if (i >= j)
            if (i && j)
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            else if (j == 0)
                c[i][j] = 1;


    ll n, m, t;
    cin >> n >> m >> t;
    ll ans = 0;
    frab(i, 4, n + 1)
        frab(j, 1, m + 1)
            if (i + j == t)
                ans += c[n][i] * c[m][j];
    cout << ans;
}