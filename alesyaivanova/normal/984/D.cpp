#include <bits/stdc++.h>

using namespace std;

int a[5000][5000];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[0][i];
    for (int k = n - 1; k >= 1; k--)
    {
        int e = n - k;
        for (int i = 0; i < k; i++)
            a[e][i] = (a[e - 1][i] ^ a[e - 1][i + 1]);
    }
    for (int k = n - 1; k >= 1; k--)
    {
        int e = n - k;
        for (int i = 0; i < k; i++)
            a[e][i] = max(a[e][i], max(a[e - 1][i], a[e - 1][i + 1]));
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << a[r - l][l] << "\n";
    }
}