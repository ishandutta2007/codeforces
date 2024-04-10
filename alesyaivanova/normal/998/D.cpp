#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int b = 0; b < 5; b++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (n - b - c + 1 > 0)
                ans += n - b - c + 1;
        }
    }
    for (int b = 5; b < 9; b++)
    {
        if (n - b + 1 > 0)
            ans += n - b + 1;
    }
    cout << ans;
}