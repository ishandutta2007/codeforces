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
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

int m[N];
int w[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    fr(i, 5)
        cin >> m[i];
    fr(i, 5)
        cin >> w[i];
    int hs, hu;
    cin >> hs >> hu;
    ll s = 0;
    fr(i, 5)
        s += max(3 * 50 * (i + 1), 500 * (i + 1) - 2 * m[i] * (i + 1) - 50 * w[i]);
    s += hs * 100 - hu * 50;
    cout << s;
}