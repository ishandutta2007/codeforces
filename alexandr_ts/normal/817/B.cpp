#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 7;
const int M = 1e3 + 5;
const int N = 1e6 + 5;
const int POW = 20;
const ll MOD = 1000 * 1000 * 1000 + 7;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    ll c1 = 0, c2 = 0, c0 = 0;
    fr(i, n) {
        if (a[i] == a[0]) c0++;
        if (a[i] == a[1]) c1++;
        if (a[i] == a[2]) c2++;
    }

    if (a[0] == a[1] && a[1] == a[2]) {
        cout << c0 * (c0 - 1) * (c0 - 2) / 6;
        return 0;
    }
    if (a[0] == a[1]) {
        cout << c2;
        return 0;
    }
    if (a[1] == a[2]) {
        cout << c2 * (c2 - 1) / 2;
        return 0;
    }
    cout << c2;
}