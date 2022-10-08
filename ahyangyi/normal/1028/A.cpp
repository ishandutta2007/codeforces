#include <iostream>

using namespace std;
int main()
{
    int n, m;
    long long x = 0, y = 0;
    int ct = 0;

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            char c;
            cin >> c;
            if (c == 'B')
            {
                ++ct;
                x += i;
                y += j;
            }
        }
    x /= ct;
    y /= ct;
    cout << x + 1 << " " << y + 1 << endl;

    return 0;
}