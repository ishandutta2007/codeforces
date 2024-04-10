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
const ll N = 2e5 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

ll a[N], l[N], r[N], d[N];
ll tree1[N], tree2[N], pref1[N], pref2[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, m, k;
    cin >> n >> m >> k;
    fr(i, n)
        cin >> a[i + 1];
    frab(i, 1, 1 + m)
        cin >> l[i] >> r[i] >> d[i];
    fr(i, k) {
        ll l, r;
        cin >> l >> r;
        tree1[r + 1]--;
        tree1[l]++;
    }
    frab(i, 1, m + 1)
        pref1[i] = pref1[i - 1] + tree1[i];
    frab(i, 1, m + 1) {
        tree2[l[i]] += d[i] * pref1[i];
        tree2[r[i] + 1] -= d[i] * pref1[i];
    }
    frab(i, 1, n + 1)
        pref2[i] = pref2[i - 1] + tree2[i];
    frab(i, 1, n + 1)
        cout << pref2[i] + a[i] << " " ;


}