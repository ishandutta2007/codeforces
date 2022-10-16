#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100005];
int b[100005];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> m;

    int A, B;
    cin >> A >> B;

    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    for (int i = 1; i <= m; ++ i)
        cin >> b[i];

    int x = a[A];
    int y = b[m - B + 1];

    if (x < y)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}