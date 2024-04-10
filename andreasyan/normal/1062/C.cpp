#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 1000000007;

int n;
char aa[N];
int a[N], p[N];

int q;

int e[N], pe[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    cin >> aa;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = aa[i - 1] - '0';
        p[i] = a[i] + p[i - 1];
    }
    e[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        e[i] = (e[i - 1] + e[i - 1]) % M;
    }
    pe[0] = e[0];
    for (int i = 1; i <= n; ++i)
    {
        pe[i] = (pe[i - 1] + e[i]) % M;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int x = p[r] - p[l - 1];
        int y = (r - l + 1) - x;
        if (y > 0)
            cout << (pe[x + y - 1] - pe[y - 1] + M) % M << endl;
        else
            cout << pe[x + y - 1] << endl;
    }
    return 0;
}