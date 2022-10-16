#include <bits/stdc++.h>

using namespace std;

int v[100005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int ans = 1;
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    int current = 1;
    for (int i = 2; i <= n; ++ i)
        if (v[i] >= v[i - 1])
            current ++;
        else {
            if (current > ans)
                ans = current;
            current = 1;
        }

    if (current > ans)
        ans = current;

    cout << ans << '\n';
    return 0;
}