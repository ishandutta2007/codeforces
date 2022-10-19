#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];

void solv()
{
    cin >> n;
    cin >> a;
    int u = N;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '8')
        {
            u = i;
            break;
        }
    }
    if (n - u >= 11)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}