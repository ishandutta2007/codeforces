#include <iostream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int n, m, gg, bb;
    cin >> n >> m >> bb;
    bool a[n], b[m];

    for(int i = 0; i < n; ++i)
        a[i] = false;
    for(int i = 0; i < m; ++i)
        b[i] = false;

    for(int i = 0; i < bb; ++i)
    {
        int t;
        cin >> t;
        a[t] = true;
    }
    cin >> gg;
    for(int i = 0; i < gg; ++i)
    {
        int t;
        cin >> t;
        b[t] = true;
    }
    for(int i = 0; i < 1000000; ++i)
    {
        if(a[i % n] or b[i % m])
            a[i % n] = b[i % m] = true;
    }
    for(int i = 0; i < n; ++i)
        if(not a[i])
        {
            cout << "No" << endl;
            return 0;
        }

    for(int i = 0; i < m; ++i)
        if(not b[i])
        {
            cout << "No" << endl;
            return 0;
        }
    cout << "Yes" << endl;
}