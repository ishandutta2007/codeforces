#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, x, y;
char a[N];

int ans;
int main()
{
    cin >> n >> x >> y >> a;
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        if (x > y)
        {
            if (a[i] == '.' && (!i || a[i - 1] != 'x') && x)
            {
                a[i] = 'x';
                x--;
                ans++;
            }
            if (a[i] == '.' && (!i || a[i - 1] != 'y') && y)
            {
                a[i] = 'y';
                y--;
                ans++;
            }
        }
        else
        {
            if (a[i] == '.' && (!i || a[i - 1] != 'y') && y)
            {
                a[i] = 'y';
                y--;
                ans++;
            }
            if (a[i] == '.' && (!i || a[i - 1] != 'x') && x)
            {
                a[i] = 'x';
                x--;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}