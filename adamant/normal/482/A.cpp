#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n - k; i++)
        cout << i << ' ';
    if(k == 1)
    {
        cout << n - 1 << ' ' << n;
        return 0;

    }
    int cur = n - k / 2;
    cout << cur << ' ';
    for(int i = 1; i <= k; i++)
        if(i % 2)
            cout << (cur = cur - i) << ' ';
        else
            cout << (cur = cur + i) << ' ';
    return 0;
}