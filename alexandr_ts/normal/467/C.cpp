#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 5e3 + 2;
const ld EPS = 1e-8;

ll d[N][N], a[N];
ll pref[N];

ll sum(ll l, ll r) {
    return pref[r] - pref[l - 1];
    //return accumulate(a + l, a + r + 1, 0ll);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n, m, k;
    cin >> n >> m >> k;
    frab(i, 1, 1 + n)
        cin >> a[i];
    frab(i, 1, 1 + n)
        pref[i] = pref[i - 1] + a[i];
    fr(i, n)
        fill(d[i], d[i] + n + 1, 0);
    frab(i, 1, 1 + n)
        fr(j, n + 1) {
            if (i >= m && j >= 1)
                d[i][j] = max(d[i][j], d[i - m][j - 1] + sum(i - m + 1, i));
            if (!j)
                d[i][j] = max(d[i][j], 0ll);
            if (i)
                d[i][j] = max(d[i][j], d[i - 1][j]);
        }
    cout << d[n][k] << endl;
//    for (int i = n; i >= 0; i--) {
//        for (int j = 0; j <= n; j++)
//            cout << d[j][i] << " ";cout << endl;}
}