#include <bits/stdc++.h>
using namespace std;
const int N = 17;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int x = 0; x < (1 << n); ++x)
    {
        int t = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                t += a[i];
            }
            else
            {
                t -= a[i];
            }
            while (t < 0)
                t += 360;
            while (t >= 360)
                t -= 360;
        }
        if (t == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}