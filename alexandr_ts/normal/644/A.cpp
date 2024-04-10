#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 1e2 + 10;
const ll MOD = 1e9 + 7;

int ar[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    if (n > a * b) {
        cout << -1;
        return 0;
    }
    int cur = 1;
    fr(i, a / 2) {
        fr(j, b) {
            if (cur == n + 1)
                break;
            ar[2 * i][j] = cur++;
        }
        for (int j = b - 1; j >= 0; j--) {
            if (cur == n + 1)
                break;
            ar[2 * i + 1][j] = cur++;
        }
    }
    if (a % 2)
        fr(j, b) {
            if (cur == n + 1)
                break;
            ar[a - 1][j] = cur++;
        }
    fr(i, a) {
        fr(j, b)
            cout << ar[i][j] << " ";
            cout << endl;}
}