#include <bits/stdc++.h>

using namespace std;

int v[55];

int main()
{
    int n = 0, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    if (k <= n) {
        k = n - k + 1;
        cout << v[k] << ' ' << v[k] << endl;
    }
    else
        cout << "-1\n";
    return 0;
}