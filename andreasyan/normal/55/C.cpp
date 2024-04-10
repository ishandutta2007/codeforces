#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n, m, k;
int x[N], y[N];

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i < k; ++i)
    {
        if (x[i] - 1 <= 4)
        {
            cout << "YES" << endl;
            return 0;
        }
        if (y[i] - 1 <= 4)
        {
            cout << "YES" << endl;
            return 0;
        }
        if (n - x[i] <= 4)
        {
            cout << "YES" << endl;
            return 0;
        }
        if (m - y[i] <= 4)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}