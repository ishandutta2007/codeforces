#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ll a, b;
    cin >> a >> b;
    if (a % 2)
        a++;
    if (a + 2 > b)
        cout << -1;
    else
        cout << a << " " << a + 1 << " " << a + 2;
    return 0;
}