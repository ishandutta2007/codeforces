#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
int a[maxn];
int b[maxn];
int n, m;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int gcd = 0;
    for (int i = 0; i < n - 1; i++)
        gcd = __gcd(gcd, a[i] - a[i + 1]);
    for (int i = 0; i < m; i++)
        cout << abs(__gcd(gcd, a[n - 1] + b[i])) << " ";
}