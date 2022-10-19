#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n;
char a[N], b[N];

int main()
{
    cin >> n;
    cin >> a >> b;
    sort(a, a + n);
    sort(b, b + n);
    int ans2 = 0;
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j < n && b[j] <= a[i])
            ++j;
        if (j < n)
        {
            ++ans2;
            ++j;
        }
    }
    int ans1 = 0;
    int i = 0;
    for (int j = 0; j < n; ++j)
    {
        if (b[j] >= a[i])
        {
            ++i;
        }
        else
        {
            ++ans1;
        }
    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}