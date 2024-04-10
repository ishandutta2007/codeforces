#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
int a[N];

int ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == 1 && a[i - 1] == 2)
            ans += 3;
        else if (a[i] == 1 && a[i - 1] == 3)
            ans += 4;
        else if (a[i] == 2 && a[i - 1] == 1)
            ans += 3;
        else if (a[i] == 3 && a[i - 1] == 1)
            ans += 4;
        else
        {
            cout << "Infinite" << endl;
            return 0;
        }
        if (i > 2 && a[i] == 2 && a[i - 1] == 1 && a[i - 2] == 3)
            ans --;
    }
    cout << "Finite" << endl << ans << endl;
    return 0;
}