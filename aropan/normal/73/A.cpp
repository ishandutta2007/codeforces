#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long a[3], x[3], m;

int main()
{
    #ifdef OFFLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    for (int i = 0; i < 3; i++)
        cin >> a[i];
    cin >> m;

    sort(a, a + 3);

    for (int i = 0; i < 3; i++)
    {
        x[i] = min(m / (3 - i), a[i] - 1);
        m -= x[i];
    }

    long long ans = 1;
    for (int i = 0; i < 3; i++)
        ans *= x[i] + 1;

    cout << ans << endl;
    return 0;
}