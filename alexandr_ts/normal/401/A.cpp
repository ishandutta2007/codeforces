#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main()
{
    int n, x;
    cin >> n >> x;
    long long sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }
    sm = abs(sm);
    if (sm == 0)
    {
        cout << 0;
        return 0;
    }
    cout << (sm - 1) / x + 1;

    return 0;
}