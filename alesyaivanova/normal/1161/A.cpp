#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair
#define pii pair<long long, long long>

const int MAXN = 100009;
int a[MAXN];
int lt[MAXN];
int rt[MAXN];
int n, k;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        lt[i] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        if (lt[a[i]] == -1)
            lt[a[i]] = i;
        rt[a[i]] = i;
    }
    int ans = 0;
    for (int e = 0; e < k; e++)
    {
        for (int j = max(0ll, e - 1); j < min(k, e + 2); j++)
        {
            if (lt[e] == -1 || lt[j] == -1 || rt[e] < lt[j])
                ans++;
        }
    }
    cout << ans;
}