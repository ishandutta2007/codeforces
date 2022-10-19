#include <bits/stdc++.h>
using namespace std;

int n, x;

bool c[3];

int main()
{
    cin >> n >> x;
    c[x] = true;
    while (c[1] == false)
    {
        if (n == 0)
            break;
        if (n % 2 == 1)
        {
            swap(c[0], c[1]);
        }
        else
        {
            swap(c[1], c[2]);
        }
        --n;
    }
    n %= 3;
    while (1)
    {
        if (n == 0)
            break;
        if (n % 2 == 1)
        {
            swap(c[0], c[1]);
        }
        else
        {
            swap(c[1], c[2]);
        }
        --n;
    }
    for (int i = 0; i < 3; ++i)
    {
        if (c[i])
        {
            cout << i << endl;
        }
    }
    return 0;
}