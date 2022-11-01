#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    if(n == 2)
    {
        cout << 2;
        return 0;
    }
    if(n % 2 == 0 && n % 3 == 0)
        cout << (max((n / 2) * (n - 1) * (n - 2), (n - 1) * (n - 2) * (n - 3)));
    else
        if(n % 2 == 0)
            cout << max(n * (n - 1) * (n - 3), (max((n / 2) * (n - 1) * (n - 2), (n - 1) * (n - 2) * (n - 3))));
    else
        cout << n * (n - 1) * (n - 2);
    return 0;
}