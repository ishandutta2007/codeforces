#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int t = (n - k) / 2;
    for (int i = 0; i < n; ++i)
    {
        if ((i + 1) % (t + 1) == 0)
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
    return 0;
}