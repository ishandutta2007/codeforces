#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
char a[N];

int main()
{
    cin >> n;
    cin >> a;
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] - '0') % 2 == 0)
            ans += (i + 1);
    }
    cout << ans << endl;
    return 0;
}