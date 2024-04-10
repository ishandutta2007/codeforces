#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int a[MAX_N];
int d[MAX_N];
int d1[MAX_N];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        d[i - 1] = a[i] - a[i - 1];
    }
    int s = a[0];
    int t = a[n - 1];
    cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        d1[i - 1] = a[i] - a[i - 1];
    }
    bool u = true;
    if (a[0] != s || a[n - 1] != t)
        u = false;
    n--;
    sort(d, d + n);
    sort(d1, d1 + n);
    for (int i = 0; i < n; i++)
    {
        if (d[i] != d1[i])
            u = false;
    }
    if (u)
        cout << "Yes";
    else
        cout << "No";
}