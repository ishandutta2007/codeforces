#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ss second
#define ff first

const int MAXN = 200009;
int a[MAXN];
int n, z;

bool check(int m)
{
    for (int i = 0; i < m; i++)
    {
        if (a[n - m + i] - a[i] < z)
            return false;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> z;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int left = 0;
    int right = n / 2 + 1;
    while (right - left > 1)
    {
        int m = (left + right) / 2;
        if (check(m))
            left = m;
        else
            right = m;
    }
    cout << left;
}