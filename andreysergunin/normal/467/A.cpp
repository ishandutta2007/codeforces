#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;


int main()
{
    long n, i, ans;
    ans = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        long p, q;
        cin >> p >> q;
        if (q - p > 1)
            ans++;
    }
    cout << ans;
}