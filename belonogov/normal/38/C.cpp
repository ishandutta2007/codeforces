#include <iostream>

using namespace std;
int a[1000];

int main()
{
    int n, l, res, res1, i, j;
    cin >> n >> l;
    for (i = 0; i < n; i++)
        cin >> a[i];
    res1 = 0;
    for (i = l; i <= 100; i++)
    {
        res = 0;
        for (j = 0; j < n; j++)
            res += (a[j] / i) * i;
        if (res1 < res)
            res1 = res;
    }
    cout << res1;

    return 0;
}