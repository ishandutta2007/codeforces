#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

const int maxn = 10000000;

int a[maxn], b[maxn];

int main()
{
    int n;
    cin >> n;
    int s1, s2, a1, b1, ans;
    s1 = 0;
    s2 = 0;
    a1 = 0;
    b1 = 0;
    ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++)
    {
        s1 = (s1 + a[i]) % 2;
        s2 = (s2 + b[i]) % 2;
    }
    if (s1 == 0 && s2 == 0)
        cout << 0;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (s1 == 1 && s2 == 1)
                if (abs((a[i] - b[i])) % 2 == 1)
                    ans = 1;
        }
        if (ans == 1)
            cout << 1;
        else
            cout << -1;
    }


    return 0;
}