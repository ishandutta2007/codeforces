#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 10;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

struct pt {
    ll x, y;
};

ld ptDist(pt a, pt b) {
    return hypotl(a.x - b.x, a.y - b.y);
}

pt a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i].x >> a[i].y;
    ld d = 0;
    fr(i, n - 1)
        d += ptDist(a[i], a[i + 1]);
    d = d * k / 50.;
    cout << fixed << setprecision(12) << d;
}