#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const int M = 2e3 + 10;
const int POW = 20;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

const int N = 1e6 + 10;

int a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    fr(i, k)
        cin >> b[i];
    sort(b, b + k);
    reverse(b, b + k);
    int cur = 0;
    fr(i, n)
        if (!a[i])
            a[i] = b[cur--];
    fr(i, n - 1)
        if (a[i] > a[i + 1]) {
            cout << "Yes";
            return 0;
        }
    cout << "No";
}