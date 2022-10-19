#include <bits/stdc++.h>
using namespace std;
const int N = 2003;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n * 2; ++i)
        cin >> a[i];
    sort(a + 1, a + n * 2 + 1);
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; ++i)
        sum1 += a[i];
    for (int i = n + 1; i <= n * 2; ++i)
        sum2 += a[i];
    if (sum1 == sum2)
        cout << -1 << endl;
    else
    {
        for (int i = 1; i <= n * 2; ++i)
            cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}