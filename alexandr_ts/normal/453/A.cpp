#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const ll MOD = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    srand(time(NULL));
    ld n, m;
    cin >> m >> n;
    ld ans = 0;
    frab(i, 1, 1 + m) {
        ans += (ld)i * pow((i / m), n) - i * pow((i - 1) / m, n);
    }
    cout << fixed << setprecision(12) << ans;
}