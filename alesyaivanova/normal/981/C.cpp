#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int num[n] = {};
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        num[a]++;
        num[b]++;
    }
    int v = -1;
    for (int i = 0; i < n; i++)
    {
        if (num[i] >= 3)
        {
            if (v != -1)
            {
                cout << "No";
                return 0;
            }
            v = i;
        }
    }
    if (v == -1)
        v = 0;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != v && num[i] == 1)
            m++;
    }
    cout << "Yes\n" << m << "\n";
    for (int i = 0; i < n; i++)
    {
        if (i != v && num[i] == 1)
        {
            cout << v + 1 << " " << i + 1 << " \n";
        }
    }
}