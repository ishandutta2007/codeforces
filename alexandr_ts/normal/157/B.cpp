#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const int MOD = 1e9 + 7;

int a[N];

int main() {
    int n, m, v, u;
    cin >> n;
    fr(i, n) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    ll sum = 0;
    fr(i, n)
        if (i % 2)
            sum -= a[i] * a[i];
        else
            sum += a[i] * a[i];
    cout << fixed << setprecision(12) << PI * (ld)sum;
}