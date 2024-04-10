#include <iostream>

using namespace std;

int a[1000000];

int main()
{
    int n, k;
    cin >> n >> k;
    int c1 = 1, c2 = n, qua = 0;
    while (qua < k)
    {
        cout << c1++ << " ";
        qua++;
        if (qua < k)
        {
            cout << c2-- << " ";
            qua++;
        }
    }
    if (c1 + c2 == n + 2)
        for (int i = c1; i <= c2; i++)
            cout << i << " ";
    else
        for (int i = c2; i >= c1; i--)
            cout << i << " ";
    return 0;
}