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
    ll n, d, m;
    cin >> n >> d;
    fr(i, n)
        cin >> a[i];
    cin >> m;
    sort(a, a + n);
    int sum = 0;
    fr(i, min(n, m))
        sum += a[i];
    m = max(0ll, m - n);
    sum -= m * d;
    cout << sum;
}