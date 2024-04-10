#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;


int main()
{
    long n, i;
    bool f;
    pair<long, long> a[100000];
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort (a, a + n);
    f = true;
    for (i = n - 1; i >= 0; i--)
    {
        if (a[i].second >= a[i - 1].first)
        {
            f = true;
            break;
        }
        else
            if (a[i].second < a[i - 1].second)
            {
                f = false;
                break;
            }
    }
    if (f)
        cout << (a[n - 1].second);
    else
        cout << (a[n - 1].first);
    return 0;
}