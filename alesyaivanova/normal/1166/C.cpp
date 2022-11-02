#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define pf emplace_front
#define ff first
#define ss second
#define pii pair<int, int>
#define mp make_pair

const int MAXN = 200009;
int a[MAXN];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(a, a + n, 2 * a[i]) - a;
        ans += j - i - 1;
    }
    cout << ans;
}