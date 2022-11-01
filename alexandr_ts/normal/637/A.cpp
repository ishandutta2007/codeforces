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
const ll N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll a[N], b[N], c[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i];
        b[a[i]]++;
    }
    int mx = *max_element(b, b + N);
    fr(i, n) {
        c[a[i]]++;
        if (c[a[i]] == mx) {
            cout << a[i];
            return 0;
        }
    }
}