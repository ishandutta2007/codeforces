#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a;
    int b;

    int ma = 10;
    int mb = 10;
    int num[10] = {};
    int mm = 10;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        num[a - 1] = 1;
        if (a < ma)
            ma = a;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        if ((num[b - 1] == 1) && b < mm)
            mm = b;
        if (b < mb)
            mb = b;
    }
    if (mm < 10)
    {
        cout << mm;
        return 0;
    }
    cout << min(ma, mb) << max(ma, mb);
}