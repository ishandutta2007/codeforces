#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ld EPS = 1e-8;

ll a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n, dx, m, dy;
    cin >> n >> dx;
    ll ans1 = 0;
    fr(i, n)
        cin >> a[i];
    cin >> m >> dy;
    fr(i, m)
        cin >> b[i];
    ll ans2 = 0;
    reverse(a, a + n);
    reverse(b, b + m);
    ll cur = 1;
    fr(i, n)
        ans1 += cur * a[i], cur *= dx;
    cur = 1;
    fr(i, m)
        ans2 += cur * b[i], cur *= dy;
    if (ans1 == ans2)
        cout << "=";
    else if (ans1 < ans2)
        cout << "<";
    else
        cout << ">";
}