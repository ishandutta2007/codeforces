#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int minu = 0, maxu = 0;
    if (k2 < k1)
    {
        swap(k2, k1);
        swap(a2, a1);
    }
    int nn = n;
    if (k1 * a1 > nn)
    {
        maxu = (nn / k1);
    }
    else
    {
        nn -= k1 * a1;
        maxu += a1;
        maxu += (nn / k2);
    }
    nn = n;
    nn -= (a1 * (k1 - 1));
    nn -= (a2 * (k2 - 1));
    if (nn > 0)
        minu = nn;
    cout << minu << ' ' << maxu << endl;
    return 0;
}