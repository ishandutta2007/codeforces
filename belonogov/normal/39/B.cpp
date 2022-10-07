#include <iostream>

using namespace std;

int main()
{
    int n, i, uk = 0, x;
    int a[1000];
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        if (uk + 1 == x)
        {
            a[uk] = 2001 + i;
            uk++;
        }
    }
    cout << uk << "\n";
    for (i = 0; i < uk; i++)
        cout << a[i] << " ";
    return 0;
}