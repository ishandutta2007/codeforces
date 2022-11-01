#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];

int nod(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int nd = 0;
    for (int i = 0; i < n; i++)
        nd = nod(nd, a[i]);
    for (int i = 0; i < n; i++)
        a[i] /= nd;
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    int ans = mx - n + 1;
    if (ans % 2 == 0)
        cout << "Alice";
    else
        cout << "Bob";
    return 0;
}