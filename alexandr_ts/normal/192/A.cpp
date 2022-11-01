#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 1e5 + 10;
const ll INF = 2e9 + 10;
const ll N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll a[M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    ll n;
    cin >> n;
    set <ll> s;
    frab(i,1, M) {
        a[i] = (i * (i + 1)) / 2;
        s.insert(a[i]);
    }
    frab(i, 1, M)
        if (s.count(n - a[i])) {
            cout << "YES";
            return 0;
        }
    cout << "NO";
}