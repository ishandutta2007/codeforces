#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m, k;
int a[N];

int b[N];
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
    {
        b[i] = a[i + 1] - a[i] - 1;
    }
    sort(b, b + n - 1);
    int kk = n;
    long long ans = n;
    for (int i = 0; i < n - 1; ++i)
    {
        if (kk == k)
            break;
        ans += b[i];
        kk--;
        if (kk == k)
            break;
    }
    cout << ans << endl;
    return 0;
}