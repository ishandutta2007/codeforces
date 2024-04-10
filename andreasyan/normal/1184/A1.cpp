#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long r;
    cin >> r;
    r -= 3;
    if (r <= 0)
        cout << "NO" << endl;
    else if (r % 2 == 0)
        cout << 1 << ' ' << r / 2 << endl;
    else
        cout << "NO" << endl;
    return 0;
}