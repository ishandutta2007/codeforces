#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e3 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

int a[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, d;
    cin >> n >> m >> d;
    fr(i, n)
        fr(j, m)
            cin >> a[i][j];
    int tmp = INF;
    fr(i, n)
        tmp = min(tmp, *min_element(a[i], a[i] + m));
    fr(i, n)
        fr(j, m)
            a[i][j] -= tmp;
    fr(i, n)
        fr(j, m)
            if (a[i][j] % d) {
                cout << -1;
                return 0;
            }
    fr(i, n)
        fr(j, m)
            a[i][j] /= d;
    int sum = INF;
    frab(i, 0, 10001) {
        int ans = 0;
        fr(i1, n)
            fr(j1, m)
                ans += abs(a[i1][j1] - i);
        sum = min(sum, ans);
    }
    cout << sum;
}