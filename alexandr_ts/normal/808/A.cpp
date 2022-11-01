#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-15;
const ld PI = acos(-1);

const int M = 1e3 + 10;
const int N = 1e6 + 10;


int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll first, len = 0;
    ll n1 = n;
    while (n1) {
        first = n1 % 10;
        n1 /= 10;
        len++;
    }
    first++;
    fr(i, len - 1)
        first *= 10;
    cout << first - n << endl;


}