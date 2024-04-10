#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int a[MAX_N];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'G')
        {
            a[i] = 1;
            cnt++;
        }
    }
    int e = 0;
    int ans = 0;
    while (e < n && a[e])
        e++;
    e++;
    while (e < n && a[e])
        e++;
    ans = max(ans, min(e, cnt));
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] == 0)
        {
            e++;
            while (e < n && a[e])
                e++;
            ans = max(ans, min(e - i, cnt));
        }
    }
    cout << ans;
}