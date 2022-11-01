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

ll a[N], b[N], c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    ll cnt0 = 0, cnt1 = 0;
    fr(i, n)
        if (a[i]) cnt1++;
        else b[i] = cnt1;
    for (ll i = n - 1; i >= 0; i--)
        if (a[i]) c[i] = cnt0;
        else cnt0++;
    cout << min(accumulate(b, b + n, 0ll), accumulate(c, c + n, 0ll));

}