#include <bits/stdc++.h>
using namespace std;
const int N = 202, INF = 999999;

int n;
char a[N];
int k;

int part(int x)
{
    int ans = 0;
    for (int i = x; i < n; ++i)
    {
        if ('a' <= a[i] && a[i] <= 'z')
        {
            if (i == n - 1 || ('a' <= a[i + 1] && a[i + 1] <= 'z'))
            {
                ++ans;
            }
        }
    }
    return ans;
}

int main()
{
    cin >> a;
    n = strlen(a);
    cin >> k;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '*')
        {
            if (i)
            {
                l--;
                r = INF;
            }
        }
        else if (a[i] == '?')
        {
            if (i)
            {
                l--;
            }
        }
        else
        {
            l++;
            r++;
        }
    }
    if (!(l <= k && k <= r))
    {
        cout << "Impossible" << endl;
        return 0;
    }
    int kk = 0;
    for (int i = 0; i < n; ++i)
    {
        if ('a' <= a[i] && a[i] <= 'z')
        {
            if (a[i + 1] == '*')
            {
                while (kk + part(i + 1) + 1 <= k)
                {
                    cout << a[i];
                    ++kk;
                }
            }
            else if (a[i + 1] == '?')
            {
                if (kk + part(i + 1) + 1 <= k)
                {
                    cout << a[i];
                    ++kk;
                }
            }
            else
            {
                cout << a[i];
                ++kk;
            }
        }
    }
    cout << endl;
    return 0;
}