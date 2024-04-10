#include <bits/stdc++.h>

using namespace std;

long long r;

int main()
{
    cin >> r;
    if (r <= 3)
    {
        cout << "NO";
        return 0;
    }
    if ((r & 1) == 0)
        cout << "NO";
    else
    {
        long long y = (r - 3) / 2;
        cout << 1 << " " << y;
    }
    return 0;
}