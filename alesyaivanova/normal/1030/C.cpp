#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (sum == 0)
    {
        cout << "YES";
        return 0;
    }
    for (int i = 1; i < sum; i++)
    {
        if (sum % i == 0)
        {
            int cur = 0;
            bool t = true;
            for (int e = 0; e < n; e++)
            {
                cur += a[e];
                if (cur == i)
                    cur = 0;
                else if (cur > i)
                {
                    t = false;
                    break;
                }
            }
            if (t)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}