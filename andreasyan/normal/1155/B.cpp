#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
char a[N];
bool c[N];

int main()
{
    cin >> n >> a;
    int nn = n;
    int i = 0, j = 0;
    while (nn != 11)
    {
        for (; i < n; ++i)
        {
            if (c[i])
                continue;
            if (a[i] != '8')
            {
                c[i] = true;
                break;
            }
        }
        for (; j < n; ++j)
        {
            if (c[j])
                continue;
            if (a[j] == '8')
            {
                c[j] = true;
                break;
            }
        }
        nn -= 2;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!c[i])
        {
            if (a[i] == '8')
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            return 0;
        }
    }
    return 0;
}