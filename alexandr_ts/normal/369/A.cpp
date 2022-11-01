#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int a[10000000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, k, temp;
    cin >> n >> m >> k;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(k > 0 && temp == 2)
            k--;
        else
        if(k <= 0 && temp == 2)
            if(m == 0)
                ans++;
            else
                m--;
        else
        if(temp == 1)
            if(m == 0)
                ans++;
            else
                m--;
    }
    cout << ans;

    return 0;
}