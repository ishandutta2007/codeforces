#include <bits/stdc++.h>

using namespace std;

int a[205];

int main()
{
    ios_base :: sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 1; i <= 2 * N; ++ i)
        cin >> a[i];
    sort(a + 1, a + 2 * N + 1);

    if (a[N] != a[N + 1])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}