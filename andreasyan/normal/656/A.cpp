#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x;
    cin >> x;
    if (x < 13)
        cout << (1LL << x);
    else
        cout << (8092LL * (1LL << (x - 13)));
    return 0;
}