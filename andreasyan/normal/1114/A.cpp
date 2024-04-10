#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = -1;

int x, y, z;
int a, b, c;

int main()
{
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if (a < x)
    {
        cout << "NO" << endl;
        return 0;
    }
    a -= x;
    if (a + b < y)
    {
        cout << "NO" << endl;
        return 0;
    }
    int mn = c + (a + b - y);
    if (mn < z)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}