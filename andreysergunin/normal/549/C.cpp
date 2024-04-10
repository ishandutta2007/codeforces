#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, a = 0, b = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            a++;
        else
            b++;
    }
    if (n == k)
    {
        if (b % 2 == 0)
            cout << "Daenerys";
        else
            cout << "Stannis";
        return 0;
    }
    if ((n - k) % 2 == 0 && k % 2 == 0)
        cout << "Daenerys";

    if ((n - k) % 2 == 0 && k % 2 != 0)
    {
        if (2 * a - 1 <= n - k)
            cout << "Stannis";
        else
            cout << "Daenerys";
    }

    if ((n - k) % 2 != 0 && k % 2 == 0)
    {
        if (a != b)
        {
            if (2 * min(a, b) <= n - k)
                cout << "Daenerys";
            else
                cout << "Stannis";
        }
        else
        {
            if (a == 1)
            {
                if (k == 2)
                    cout << "Stannis";
                else
                    cout << "Daenerys";
            }
            else
            {
                if (2 * (a - 1) <= n - k)
                    cout << "Daenerys";
                else
                    cout << "Stannis";
            }
        }
    }


    if ((n - k) % 2 != 0 && k % 2 != 0)
    {
        if (2 * b <= n - k)
            cout << "Daenerys";
        else
            cout << "Stannis";
    }

    return 0;
}