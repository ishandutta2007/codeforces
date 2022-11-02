#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int INF = 2e9;
const ld EPS = 1e-16;

int a[N], pos[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ld start = clock() / CLOCKS_PER_SEC;
    srand(time(NULL));
    //freopen("spacepin.in", "r", stdin);
    //freopen("spacepin.out", "w", stdout);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i + 1];
        pos[a[i + 1]] = i + 1;
    }
    int st = pos[1];
    ll ans = 0;
    frab(i, 2, n + 1) {
        ans += abs(pos[i] - st);
        st = pos[i];
    }
    cout << ans;

}