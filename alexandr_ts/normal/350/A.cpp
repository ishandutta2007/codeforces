#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int b[1000000], a[10000000];

int main()
{
    int n;
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int maxx = a[0];
    int mmin = a[0];
    int minnn = b[0];
    for (int i = 0; i < m; i++)
        if (b[i] < minnn)
            minnn = b[i];
    for (int i = 0; i < n; i++){
        if (a[i] > maxx)
            maxx = a[i];
        if (a[i] < mmin)
            mmin = a[i];
    }
    mmin = 2 * mmin;
    if (minnn <= max(mmin, maxx))
        cout << -1;
    else
        cout << max(mmin, maxx);
    return 0;
}