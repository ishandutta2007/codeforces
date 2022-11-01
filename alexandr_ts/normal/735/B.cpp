#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, n1, n2;
    cin >> n >> n1 >> n2;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    if (n1 < n2)
        swap(n1, n2);
    ll sum = 0;
    fr(i, n2)
        sum += a[i];
    ll sum2 = 0;
    frab(i, n2, n2 + n1)
        sum2 += a[i];
    cout << fixed << setprecision(12) << (ld)sum / n2 + (ld)sum2 / n1;
}