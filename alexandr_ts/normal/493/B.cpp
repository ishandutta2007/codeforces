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

vector <ll> b, c;
ll a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    fr(i, n) {
        cin >> a[i];
        if (a[i] > 0)
            b.pb(a[i]);
        else
            c.pb(-a[i]);
    }
    if (accumulate(b.begin(), b.end(), 0ll) > accumulate(c.begin(), c.end(), 0ll)) {
        cout << "first";
        return 0;
    }
    if (accumulate(b.begin(), b.end(), 0ll) < accumulate(c.begin(), c.end(), 0ll)) {
        cout << "second";
        return 0;
    }
    if (b > c) {
        cout << "first";
        return 0;
    }
    if (b < c) {
        cout << "second";
        return 0;
    }
    if (a[n - 1] > 0)
        cout << "first";
    else
        cout << "second";
}