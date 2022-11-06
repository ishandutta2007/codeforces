#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

int n, i;
string a, b, c, d;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> a >> b;
    cin >> n;

    for (i = 1; i <= n; i++) {
        cout << a << ' ' << b << '\n';

        cin >> c >> d;
        if (a == c)
            a = d;
        else
            b = d;
    }

    cout << a << ' ' << b << '\n';


    return 0;
}