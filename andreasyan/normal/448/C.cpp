#include <bits/stdc++.h>
using namespace std;
const int N = 5003;

int n;
int a[N];

int qry(int l, int r)
{
    int minu = a[l];
    for (int i = l; i <= r; ++i)
        minu = min(minu, a[i]);
    for (int i = l; i <= r; ++i)
        a[i] -= minu;
    int ans = 0;
    int ll = -1;
    for (int i = l; i <= r; ++i)
    {
        if (a[i])
        {
            if (ll == -1)
                ll = i;
        }
        else
        {
            if (ll != -1 && a[i - 1])
                ans += qry(ll, i - 1);
        }
    }
    if (a[r])
        ans += qry(ll, r);
    return min(ans + minu, r - l + 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << qry(1, n) << endl;
    return 0;
}