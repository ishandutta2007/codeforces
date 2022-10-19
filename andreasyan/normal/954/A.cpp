#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];

int main()
{
    cin >> n >> a;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] == 'U' && a[i + 1] == 'R') || (a[i] == 'R' && a[i + 1] == 'U'))
        {
            ++i;
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}