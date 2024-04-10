#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;


int main() {
    //freopen("sweets.in", "r", stdin);
    int h, m;
    scanf("%d:%d", &h, &m);
    int m2;
    cin >> m2;
    int m1 = m + 60 * h + m2;
    m = m1 % 60;
    m2 = m1 / 60 % 24;
    if (m2 < 10)
        cout << 0;
    cout << m2 << ":";
    if (m < 10)
        cout << 0;
    cout << m;

}