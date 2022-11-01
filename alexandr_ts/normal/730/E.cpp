#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 1e6 + 10;
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 5e5 + 10;

int a[N], d[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i] >> d[i];

    int ans1 = 0;
    fr(i, n)
        frab(j, i + 1, n) {
            int ans = 0;
            pair <int, int> a1 = mp(a[i], -i), a2 = mp(a[i] + d[i], -i);
            pair <int, int> b1 = mp(a[j], -j), b2 = mp(a[j] + d[j], -j);
            int t = 0;
            if (a1 < b1 && b1 < a2 && a2 < b2) ans += 2;
            else if (b1 < a1 && a1 < b2 && b2 < a2) ans += 2;
            else if (a1 > b1 && b1 > a2 && a2 > b2) ans += 2;
            else if (b1 > a1 && a1 > b2 && b2 > a2) ans += 2;
            else if (min(a1, a2) < min(b1, b2) && max(b1, b2) < max(a1, a2)) ans++;
            else if (min(b1, b2) < min(a1, a2) && max(a1, a2) < max(b1, b2)) ans++;
            else if (b2 < a1 && a1 < b1 && b1 < a2) ans++;
            else if (a2 < b1 && b1 < a1 && a1 < b2) ans++;
            else if (a1 < b2 && b2 < a2 && a2 < b1) ans++;
            else if (b1 < a2 && a2 < b2 && b2 < a1) ans++;
            //cout << i << " " << j << " " << ans << endl;
            ans1 += ans;
        }
    cout << ans1;

}