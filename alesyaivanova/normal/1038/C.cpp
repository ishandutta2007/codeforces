#include <bits/stdc++.h>

using namespace std;

int a[100010];
int b[100010];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a, a + n + 1);
    sort(b, b + n + 1);
    int na = n + 1;
    int nb = n + 1;
    long long sa = 0;
    long long sb = 0;
    for (int i = 0; i < n; i++)
    {
        if (na == 1)
            nb--;
        else if (nb == 1)
        {
            sa += a[na - 1];
            na--;
        }
        else
        {
            if (a[na - 1] >= b[nb - 1])
            {
                sa += a[na - 1];
                na--;
            }
            else
                nb--;
        }

        if (nb == 1)
            na--;
        else if (na == 1)
        {
            sb += b[nb - 1];
            nb--;
        }
        else
        {
            if (b[nb - 1] >= a[na - 1])
            {
                sb += b[nb - 1];
                nb--;
            }
            else
                na--;
        }
    }
    cout << sa - sb;
}