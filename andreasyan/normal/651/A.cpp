#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    while (1)
    {
        if (a > b)
            swap(a, b);
        if (a < 1 || b < 2)
            break;
        ++ans;
        ++a;
        b -= 2;
    }
    cout << ans << endl;
    return 0;
}