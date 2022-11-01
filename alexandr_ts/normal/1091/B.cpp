#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 9;
const ll INF = 2e15 + 10;
const ll MAX = 1e14 + 10;
const ld EPS = 1e-9;
const int N = 1e6 + 10;


void solve() {
    int n;
    cin >> n;
    ll x1, y1, xs = 0, ys = 0;
    fr(i, n) {
        cin >> x1 >> y1;
        xs += x1, ys += y1;
    }
    fr(i, n) {
        cin >> x1 >> y1;
        xs += x1, ys += y1;
    }
    cout << xs / n << " " << ys / n;
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    solve();
}