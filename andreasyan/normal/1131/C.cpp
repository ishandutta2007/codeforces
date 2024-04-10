#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
int a[N];

int ans[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int j = 1, k = n;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2)
            ans[j++] = a[i];
        else
            ans[k--] = a[i];
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}