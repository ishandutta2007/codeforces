#include <bits/stdc++.h>
using namespace std;

int l, r, a;

int main()
{
    cin >> l >> r >> a;
    if (r < l)
        swap(l, r);
    if (l + a <= r)
    {
        l += a;
        cout << l * 2 << endl;
        return 0;
    }
    a -= (r - l);
    l = r;
    cout << (l + (a / 2)) * 2 << endl;
    return 0;
}