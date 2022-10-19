#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];

int u;
int q[N];
int qq[N];
int qu;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i == n)
            cout << "";
        if (!q[a[i]])
            ++u;

        if (q[a[i]])
        {
            qq[q[a[i]]]--;
            if (qq[q[a[i]]] == 0)
                qu--;
        }

        q[a[i]]++;

        qq[q[a[i]]]++;
        if (qq[q[a[i]]] == 1)
            qu++;

        if (qq[q[a[i]]] + qq[q[a[i]] - 1] == u)
        {
            if (qq[q[a[i]]] == 1)
                ans = i;
        }
        if (qq[q[a[i]]] + qq[q[a[i]] + 1] == u)
        {
            if (qq[q[a[i]]] == u - 1)
                ans = i;
        }
        if (qq[1] == 1 && qu == 2)
            ans = i;
        if (qq[1] >= 1 && qu == 1)
            ans = i;
    }
    cout << ans << endl;
    return 0;
}