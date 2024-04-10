#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < (ll)n; i++)
#define frab(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e6 + 10;
const ll INF = 2e9;
const ll ALPH = 300;

int a[N], c[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i] >> c[i];
    int mn = INF, ans = 0;
    fr(i, n) {
        mn = min(mn, c[i]);
        ans += a[i] * mn;
    }
    cout << ans;
}