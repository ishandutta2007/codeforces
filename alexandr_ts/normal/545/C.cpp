#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e12 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

ll x[N], h[N], l[N], r[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    fr(i, n) {
        cin >> x[i] >> h[i];
    }
    ll q = 1;
    ll last = x[0];

    frab(i, 1, n) {
        if (x[i] - h[i] > last) {
            q++;
            last = x[i];
        }
        else if (i == n - 1 || (x[i + 1] > x[i] + h[i])) {
            q++;
            last = x[i] + h[i];
        }
        else
            last = x[i];
    }

    cout << q;
}