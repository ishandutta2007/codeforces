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

char a[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    ll x1 = INF, x2 = -INF, y1 = INF, y2 = -INF;
    cin >> n >> m;
    fr(i, n)
        fr(j, m) {
            cin >> a[i][j];
            if (a[i][j] == '*')
                x1 = min(x1, i), x2 = max(x2, i), y1 = min(y1, j), y2 = max(y2, j);
        }
    frab(i, x1, x2 + 1) {
        frab(j, y1, y2 + 1)
            cout << a[i][j];cout << endl;}
}