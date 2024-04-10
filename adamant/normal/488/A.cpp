#include <bits/stdc++.h>

using namespace std;
#define int int64_t
bool check(int x)
{
    x = abs(x);
    while(x)
    {
        if(x % 10 == 8) return 1;
        x /= 10;
    }
    return 0;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= 100; i++)
        if(check(n + i))
        {
            cout << i;
            return 0;
        }
}