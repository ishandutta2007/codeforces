#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n = 100;
int a[N], b[N];

int main()
{
    for (int x = 1; x <= 100; ++x)
    {
        a[x] = x;
        b[x] = (x << 7);
    }
    int y1, y2;
    cout << "?";
    for (int i = 1; i <= n; ++i)
        cout << ' ' << a[i];
    cout << endl;
    cin >> y1;
    cout << "?";
    for (int i = 1; i <= n; ++i)
        cout << ' ' << b[i];
    cout << endl;
    cin >> y2;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if ((a[i] ^ b[j]) == (y1 ^ y2))
            {
                cout << "! " << (y1 ^ a[i]) << endl;
                return 0;
            }
        }
    }
    return 0;
}