#include <bits/stdc++.h>
using namespace std;
const int N = 302;

int n;
char a[N];

void solv()
{
    cin >> n;
    cin >> a;
    if (n == 2)
    {
        if (a[0] < a[1])
        {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << a[0] << ' ' << a[1] << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << a[0] << ' ';
        for (int i = 1; i < n; ++i)
            cout << a[i];
        cout << endl;
    }
}

int main()
{
    int q;
    cin >> q;
    while (q--)
        solv();
    return 0;
}