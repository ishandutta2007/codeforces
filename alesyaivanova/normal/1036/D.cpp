#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300010;
int n, m;
int a[MAX_N];
int b[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int i = 0;
    int e = 0;
    long long sa = 0;
    long long sb = 0;
    int ans = 0;
    while (i <= n && e <= m)
    {
        if (i < n && sa <= sb)
        {
            sa += a[i];
            i++;
            if (sa == sb)
                ans++;
        }
        else if (e < m && sb <= sa)
        {
            sb += b[e];
            e++;
            if (sa == sb)
                ans++;
        }
        else
            break;
    }
    if (i != n || e != m || sa != sb)
        cout << -1;
    else
        cout << ans;
}