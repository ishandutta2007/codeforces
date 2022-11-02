#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int s[n];
    int c[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int pr[n];
    for (int i = 0; i < n; i++)
    {
        pr[i] = -1;
        for (int e = 0; e < i; e++)
        {
            if (s[e] < s[i])
            {
                if (pr[i] == -1 || c[pr[i]] > c[e])
                    pr[i] = e;
            }
        }
    }
    int pr1[n];
    int m[n];
    for (int i = 0; i < n; i++)
    {
        pr1[i] = -1;
        int mi;
        m[i] = -1;
        for (int e = 0; e < i; e++)
        {
            if (s[e] < s[i] && pr[e] != -1)
            {
                if (pr1[i] == -1 || c[pr[e]] + c[e] < mi)
                {
                    pr1[i] = e;
                    mi = c[pr[e]] + c[e];
                    m[i] = mi + c[i];
                }
            }
        }
    }
    int mi = -1;
    for (int i = 0; i < n; i++)
    {
        if (mi == -1)
            mi = m[i];
        else if (m[i] != -1)
            mi = min(mi, m[i]);
    }
    cout << mi;
}