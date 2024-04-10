#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e5 + 10;
int n, a[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int mx = 0, mn = n + 1;
        for (int i = 1; i < n; ++i)
            if (a[i] == a[i + 1]) mx = max(mx, i), mn = min(mn, i);
        if (mx <= mn + 1) cout << max(0, mx - mn) << "\n";
        else cout << mx - mn - 1 << "\n";
    }
    return 0;
}