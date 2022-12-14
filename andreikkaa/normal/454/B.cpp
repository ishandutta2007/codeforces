#include <iostream>
#include <algorithm>
#include <memory.h>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 2];
    bool l[n + 2];
    bool r[n + 2];
    a[0] = - 1e+9;
    a[n + 1] = 1e+9;
    memset(l, 0, sizeof(bool) * (n + 2));
    memset(r, 0, sizeof(bool) * (n + 2));
    l[0] = l[n + 1] = r[0] = r[n + 1] = true;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] >= a[i - 1])
            l[i] = l[i - 1];
        else
            l[i] = false;
    }

    for(int i = n; i >= 1; --i)
    {
        if(a[i] <= a[i + 1])
            r[i] = r[i + 1];
        else
            r[i] = false;
    }

    if(l[n])
    {
        cout << 0 << endl;
        return 0;
    }
    if(a[n] > a[1])
    {
        cout << -1 << endl;
        return 0;
    }

    for(int i = n; i >= 1; --i)
    {
        //r[i] and l[i - 1]
        if(r[i] and l[i - 1])
        {
            cout << n - i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

}