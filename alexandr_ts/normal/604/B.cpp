#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i + 1];
    int ans = a[n];
    frab(i, 1, n - k + 1)
        ans = max(ans, a[i] + a[2 * n - 2 * k - i + 1]);
    cout << ans;
}