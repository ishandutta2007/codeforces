#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    int q;
    cin >> q;
    while (q--)
    {
        long long x;
        cin >> x;
        while ((x % 2) == 0)
        {
            x += (n - (x / 2));
        }
        cout << (x / 2) + 1 << endl;
    }
    return 0;
}