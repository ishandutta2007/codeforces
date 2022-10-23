#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
int n, a[N], b[N];

bool check(int x)
{
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; ++i) s1 += a[i], s2 += b[i];
    s1 += 100 * x;
    int k = (n + x) / 4;
    for (int i = 1; i <= k; ++i) s1 -= a[i];
    k -= x;
    for (int i = 1; i <= k; ++i) s2 -= b[i];
    return (s1 >= s2);
}

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
        for (int j = 1; j <= n; ++j) cin >> b[j];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        int l = 0, r = 3 * n + 3, ans = 3 * n + 3;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}