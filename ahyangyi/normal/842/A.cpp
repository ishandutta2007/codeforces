#include <iostream>

using namespace std;

int main()
{
    int l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    l = (l + k - 1) / k;
    r = r / k;
    int mi = min(r, y);
    int ma = max(l, x);
    if (ma <= mi)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}